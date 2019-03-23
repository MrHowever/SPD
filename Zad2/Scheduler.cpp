//
// Created by mrhowever on 10.03.19.
//

#include "Scheduler.hh"
#include "Task.hh"
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