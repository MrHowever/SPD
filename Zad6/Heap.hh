//
// Created by mrhowever on 16.04.19.
//

#ifndef ZAD5_HEAP_HH
#define ZAD5_HEAP_HH

#include <vector>
#include "Task.hh"
#include "FileReader.hh"

enum HeapType : unsigned int {MAXHEAP, MINHEAP};

class Heap {

    HeapType heapType;
    bool (*compare)(const Task&, const Task&);

    unsigned int leftSon(unsigned int i) { return (i+1)*2 - 1; }
    unsigned int rightSon(unsigned int i) { return (i+1)*2; }
    unsigned int parent(unsigned int i) { return i % 2 == 0 ? (i/2) - 1 : ((i+1)/2) - 1; }
    void heapify(unsigned int);

public:
    Heap(const Tasks&, HeapType);
    std::vector<Task> heap;
    void insert(const Task&);
    Task getRoot();
    bool empty() { return heap.empty(); }
};


#endif //ZAD5_HEAP_HH
