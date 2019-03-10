//
// Created by mrhowever on 10.03.19.
//

#include "Scheduler.hh"
#include "Task.hh"
#include <algorithm>
#include <numeric>
#include <limits>
#include <iostream>

std::vector<std::vector<int> > Scheduler::permutations(int machineCount)
{
    std::vector<int> indices(machineCount);
    std::vector<std::vector<int> > permutationVec;

    std::iota(indices.begin(),indices.end(),0);

    do {
        permutationVec.push_back(indices);
    } while(std::next_permutation(indices.begin(),indices.end()));

    return permutationVec;
}

std::vector<int> Scheduler::johnsonsRule(std::vector<Task>& tasks)
{
    if(tasks[0].machineTime.size() > 3)
        std::cerr<<"Invalid number of machines\n";

    std::vector<int> order = tasks.size() == 2 ? johnsonsRule2(tasks) : johnsonsRule3(tasks);
    return order;
}

std::vector<int> Scheduler::johnsonsRule3(std::vector<Task> tasks)
{
    for(auto& task : tasks)
    {
        task.machineTime[0] = task.machineTime[0] + task.machineTime[1];
        task.machineTime[1] = task.machineTime[1] + task.machineTime[2];
        task.machineTime.erase(task.machineTime.begin() + 2);
    }

    return johnsonsRule2(tasks);
}

std::vector<int> Scheduler::johnsonsRule2(std::vector<Task> tasks)
{
    std::vector<int> order(tasks.size());
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