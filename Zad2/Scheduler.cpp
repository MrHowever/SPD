//
// Created by mrhowever on 10.03.19.
//

#include "Scheduler.hh"
#include "Task.hh"
#include "Controller.hh"
#include "FlowshopGraph.hh"
#include <algorithm>
#include <numeric>
#include <limits>
#include <iostream>

//Funkcja zwracajaca wektor wszystkich permutacji kolejnosci zadan dla ilosci zadan podanej jako parametr
std::vector<Order> Scheduler::permutations(int taskCount)
{
    std::vector<int> indices(taskCount);
    std::vector<Order> permutationVec;

    std::iota(indices.begin(),indices.end(),0);

    do {
        permutationVec.push_back(indices);
    } while(std::next_permutation(indices.begin(),indices.end()));

    return permutationVec;
}

//Funkcja zwracajaca kolejnosc wykonania zadan zgodnie z zasada Johnsona
Order Scheduler::johnsonsRule(std::vector<Task>& tasks)
{
    if(tasks[0].machineTime.size() > 3) {
        std::cerr << "Invalid number of machines\n";
        return std::vector<int>();
    }

    Order order = tasks[0].machineTime.size() == 2 ? johnsonsRule2(tasks) : johnsonsRule3(tasks);

    return order;
}

//Funkcja zwracajaca kolejnosc wykonania zadan zgodnie z regula Johnsona dla 3 maszyn
Order Scheduler::johnsonsRule3(std::vector<Task> tasks)
{
    for(auto& task : tasks)
    {
        task.machineTime[0] = task.machineTime[0] + task.machineTime[1];
        task.machineTime[1] = task.machineTime[1] + task.machineTime[2];
        task.machineTime.erase(task.machineTime.begin() + 2);
    }

    return johnsonsRule2(tasks);
}

//Funkcja zwracajaca kolejnosc wykonania zadan zgodnie z regula Johnsona dla 2 maszyn
Order Scheduler::johnsonsRule2(std::vector<Task> tasks)
{
    Order order(tasks.size());
    std::vector<int>::iterator front = order.begin();
    std::vector<int>::reverse_iterator back = order.rbegin();
    int shortestTime = std::numeric_limits<int>::max();
    int shortestTask = 1;
    int machine = 0;

    while(!tasks.empty()) {
        for (std::vector<Task>::size_type i = 0; i < tasks.size(); i++) {
            for (std::vector<int>::size_type j = 0; j < tasks[i].machineTime.size(); j++) {
                if (tasks[i].machineTime[j] < shortestTime) {
                    shortestTime = tasks[i].machineTime[j];
                    shortestTask = i;
                    machine = j;
                }
            }
        }

        if(machine)
            *back++ = tasks[shortestTask].taskID;
        else
            *front++ = tasks[shortestTask].taskID;

        tasks.erase(tasks.begin() + shortestTask);
        shortestTime = std::numeric_limits<int>::max();
    }

    return order;
}

Order Scheduler::nehOrder(std::vector<Task> tasks)
{
    std::vector<std::pair<int,int> > priorities(tasks.size());
    std::vector<std::pair<int,int> >::iterator it = priorities.begin();
    Order priorityOrder(tasks.size());
    Order currentOrder;

    //Calculate priority value for each task
    for(int i = 0; i < tasks.size(); i++) {
        for (auto& time : tasks[i].machineTime)
            (*it).first += time;

        (*it).second = i;
        it++;
    }

    //Sort tasks by priority
    std::sort(priorities.rbegin(), priorities.rend(), Scheduler::comparePriorities);      //Reverse iterators are used to accomplish descending order

    for(int i = 0; i < priorities.size(); i++)
        priorityOrder[i] = priorities[i].second;


    //Calculate NEH order
    Controller tempController(tasks);
    for(int i = 0; i < priorityOrder.size(); i++) {
        std::vector<int> cmaxArr(i+1);
        for(int j = 0; j < (i+1); j++) {
            Order tempOrder = currentOrder;
            tempOrder.insert(tempOrder.begin()+j,priorityOrder[i]);
            cmaxArr[j] = tempController.calculateTask(tempOrder);
            tempController.resetMachines();
        }

        long lowestCmaxIdx = std::distance(cmaxArr.begin(), std::min_element(cmaxArr.begin(),cmaxArr.end()));
        currentOrder.insert(currentOrder.begin() + lowestCmaxIdx, priorityOrder[i]);

        long shuffleIdx = extendNEHPickIdx(currentOrder,tasks,LONGEST,0);

        currentOrder.erase(std::remove(currentOrder.begin(), currentOrder.end(), shuffleIdx),currentOrder.end());

        std::vector<int> cmaxArr2(i+1);
        for(int j = 0; j < (i+1); j++) {
            Order tempOrder = currentOrder;
            tempOrder.insert(tempOrder.begin()+j,shuffleIdx);
            cmaxArr2[j] = tempController.calculateTask(tempOrder);
            tempController.resetMachines();
        }

        lowestCmaxIdx = std::distance(cmaxArr2.begin(), std::min_element(cmaxArr2.begin(),cmaxArr2.end()));
        currentOrder.insert(currentOrder.begin() + lowestCmaxIdx, shuffleIdx);
    }

    return currentOrder
    ;
}

long Scheduler::extendNEHPickIdx(Order& order, std::vector<Task> tasks, ExtendedNEHType type, long ignoreIdx)
{
    switch(type)
    {
        case LONGEST:
            return FlowshopGraph::longestCriticalOperation(tasks,order,ignoreIdx);
        case SUM:
            return FlowshopGraph::longestSumOfCriticalOperations(tasks,order,ignoreIdx);
        case BIGGEST:
            return FlowshopGraph::mostCriticalOperations(tasks,order,ignoreIdx);
        case REMOVAL:
            return bestRemovalIdx(order,tasks,ignoreIdx);
    }

    return 0;
}

int Scheduler::bestRemovalIdx(Order order, std::vector<Task> tasks,long ignoreIdx)
{
    Controller controller(tasks);
    std::vector<int> cmaxArr(order.size());
    int currentCmax = controller.calculateTask(order);


    for(int i = 0; i < order.size(); i++) {
        Order tempOrder = order;
        tempOrder.erase(tempOrder.begin() + i);
        cmaxArr[i] = currentCmax - controller.calculateTask(tempOrder);
    }

    cmaxArr.erase(cmaxArr.begin() + ignoreIdx);

    return (int) std::distance(cmaxArr.begin(), std::max_element(cmaxArr.begin(),cmaxArr.end()));
}

bool Scheduler::comparePriorities(std::pair<int,int>& first, std::pair<int,int>& second)
{
    return first.first <         second.first;
}

Order Scheduler::insertIntoOrder(int taskID, Order& order)
{

}