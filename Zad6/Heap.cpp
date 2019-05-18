//
// Created by mrhowever on 16.04.19.
//

#include <cmath>
#include <iostream>
#include "Heap.hh"
#include "Task.hh"
#include "Schrage.hh"

bool smallerR(const Task& task1, const Task& task2)
{
    return task1.r < task2.r;
}

bool biggerQ(const Task& task1, const Task& task2)
{
    return task1.q > task2.q;
}


Heap::Heap(const Tasks& tasks, HeapType type)
{
    heap = tasks;
    compare = type == MAXHEAP ? &biggerQ : &smallerR;

    for(int i = std::floor(heap.size()/2); i >= 0; i--)
        heapify(i);
}

void Heap::heapify(unsigned int i)
{
    unsigned int left = leftSon(i);
    unsigned int right = rightSon(i);
    unsigned int current = i;

    if( left < heap.size() && compare(heap[left],heap[current]))
        current = left;

    if( right < heap.size() && compare(heap[right],heap[current]))
        current = right;

    if(current != i) {
        std::swap(heap[i],heap[current]);
        heapify(current);
    }
}

void Heap::insert(const Task& task)
{
    heap.push_back(task);
    unsigned int taskIdx = heap.size()-1;

    while( taskIdx != 0 && compare(heap[taskIdx],heap[parent(taskIdx)])) {
        std::swap(heap[taskIdx],heap[parent(taskIdx)]);
        taskIdx = parent(taskIdx);
    };
}

Task Heap::getRoot()
{
    Task root = heap[0];

    std::swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();

    heapify(0);

    return root;
}
