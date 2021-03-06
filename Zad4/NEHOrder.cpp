//
// Created by mrhowever on 29.03.19.
//

#include "NEHOrder.hh"
#include "Controller.hh"
#include "FlowshopGraph.hh"
#include "Tester.hh"
#include <algorithm>

Order NEHOrder::order(Tasks& tasks)
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
    std::sort(priorities.rbegin(), priorities.rend(), NEHOrder::comparePriorities);      //Reverse iterators are used to accomplish descending order

    for(int i = 0; i < priorities.size(); i++)
        priorityOrder[i] = priorities[i].second;


    //Calculate NEH order
    Controller tempController(tasks);
    for(int i = 0; i < priorityOrder.size(); i++) {
        long lowestCmaxIdx = 0;

        if(currentOrder.size() > 0) {
            if (acceleration) {
                lowestCmaxIdx = lowestCmaxIndex(longestInPath(tasks, currentOrder), longestOutPath(tasks, currentOrder),
                                                tasks[priorityOrder[i]]);
            }
            else {
                std::vector<int> cmaxArr(i + 1);
                for (int j = 0; j < (i + 1); j++) {
                    Order tempOrder = currentOrder;
                    tempOrder.insert(tempOrder.begin() + j, priorityOrder[i]);
                    cmaxArr[j] = tempController.calculateCmax(tempOrder);
                    tempController.resetMachines();
                }

                lowestCmaxIdx = std::distance(cmaxArr.begin(), std::min_element(cmaxArr.begin(), cmaxArr.end()));
            }
        }

        currentOrder.insert(currentOrder.begin() + lowestCmaxIdx, priorityOrder[i]);

        //Returns task ID not task INDEX!
        if(currentOrder.size() > 2 && type != NONE) {
            currentOrder = extendedNEH(currentOrder,tasks,lowestCmaxIdx);
        }

    }

    return currentOrder;
}

Order NEHOrder::extendedNEH(Order& currentOrder, Tasks& tasks, long ignoreIdx)
{
    Controller tempController(tasks);
    long lowestCmaxIdx = 0;

    if(currentOrder.size() > 2) {
        long taskID = extendNEHPickIdx(currentOrder, tasks, type, ignoreIdx);

        currentOrder.erase(std::remove(currentOrder.begin(), currentOrder.end(), taskID), currentOrder.end());

        std::vector<int> cmaxArr(currentOrder.size() + 1);
        for (int j = 0; j < (currentOrder.size() + 1); j++) {
            Order tempOrder = currentOrder;
            tempOrder.insert(tempOrder.begin() + j, taskID);
            cmaxArr[j] = tempController.calculateCmax(tempOrder);
            tempController.resetMachines();
        }

        lowestCmaxIdx = std::distance(cmaxArr.begin(), std::min_element(cmaxArr.begin(), cmaxArr.end()));

        currentOrder.insert(currentOrder.begin() + lowestCmaxIdx, taskID);
    }

    return currentOrder;
}

long NEHOrder::lowestCmaxIndex(std::vector<std::vector<int> > inPath, std::vector<std::vector<int> > outPath, Task task)
{
    if(inPath.empty())
        return 0;

    int machines = task.machineTime.size();
    std::vector<int> cmaxArr(inPath[0].size()+1);

    for(int j = 0; j < inPath[0].size() + 1; j++) {
        std::vector<int> cVec(machines);
        std::vector<int> cVecMax(machines);
        for(int i = 0; i < machines; i++) {
            int inPathComp = j == 0 ? 0 : inPath[i][j-1];
            int outPathComp = j == inPath[0].size() ? 0 : outPath[i][j];
            int parentComp = i == 0 ? 0 : cVec[i-1];

            cVec[i] = task.machineTime[i] + std::max(inPathComp,parentComp);
            cVecMax[i] = cVec[i] + outPathComp;
        }

        cmaxArr[j] = *(std::max_element(cVecMax.begin(),cVecMax.end()));
    }

    return std::distance(cmaxArr.begin(),std::min_element(cmaxArr.begin(),cmaxArr.end()));
}

std::vector<std::vector<int> > NEHOrder::longestInPath(std::vector<Task>& tasks, Order order)
{
    if(order.empty())
        return std::vector<std::vector<int> >();

    std::vector<std::vector<int> > vec(tasks[0].machineTime.size());

    for(auto& elem : vec)
        elem = std::vector<int>(order.size());

    vec[0][0] = tasks[order[0]].machineTime[0];

    for(int i = 1; i < order.size(); i++)
        vec[0][i] = tasks[order[i]].machineTime[0] + vec[0][i-1];

    for(int i = 1; i < tasks[0].machineTime.size(); i++)
        vec[i][0] = tasks[order[0]].machineTime[i] + vec[i-1][0];

    for(int i = 1; i < order.size(); i++)
        for(int j = 1; j < tasks[0].machineTime.size(); j++) {
            int biggerVal = vec[j - 1][i] > vec[j][i - 1] ? vec[j-1][i] : vec[j][i-1];
            vec[j][i] = biggerVal + tasks[order[i]].machineTime[j];
        }

    return vec;
}


std::vector<std::vector<int> > NEHOrder::longestOutPath(std::vector<Task>& tasks, Order order)
{
    if(order.empty())
        return std::vector<std::vector<int> >();

    std::vector<std::vector<int> > vec(tasks[0].machineTime.size());

    int width = order.size()-1;
    int height = tasks[0].machineTime.size() - 1;

    for(auto& elem : vec)
        elem = std::vector<int>(order.size());

    vec[height][width] = tasks[order[width]].machineTime[height];

    for(int i = width - 1; i >= 0; i--)
        vec[height][i] = tasks[order[i]].machineTime[height] + vec[height][i+1];

    for(int i = height - 1; i >= 0; i--)
        vec[i][width] = tasks[order[width]].machineTime[i] + vec[i+1][width];

    for(int i = width - 1; i >= 0; i--)
        for(int j = height - 1; j >= 0; j--) {
            int biggerVal = vec[j + 1][i] > vec[j][i + 1] ? vec[j+1][i] : vec[j][i+1];
            vec[j][i] = biggerVal + tasks[order[i]].machineTime[j];
        }

    return vec;
}


long NEHOrder::extendNEHPickIdx(Order& order, Tasks tasks, ExtendedNEHType type, long ignoreIdx)
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

int NEHOrder::bestRemovalIdx(Order order, Tasks tasks,long ignoreIdx)
{
    Controller controller(tasks);
    std::vector<int> cmaxArr(order.size());
    int currentCmax = controller.calculateCmax(order);


    for(int i = 0; i < order.size(); i++) {
        Order tempOrder = order;
        tempOrder.erase(tempOrder.begin() + i);
        cmaxArr[i] = currentCmax - controller.calculateCmax(tempOrder);
    }

    cmaxArr.erase(cmaxArr.begin() + ignoreIdx);

    return order[std::distance(cmaxArr.begin(), std::max_element(cmaxArr.begin(),cmaxArr.end()))];
}

bool NEHOrder::comparePriorities(std::pair<int,int>& first, std::pair<int,int>& second)
{
    return first.first <         second.first;
}
