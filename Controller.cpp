//
// Created by mrhowever on 09.03.19.
//

#include "Controller.hh"
#include "Scheduler.hh"
#include <iostream>
#include <random>

Controller::Controller(std::vector<std::vector<int> > input)
{
    for(std::vector<int>::size_type i = 0; i < input.size(); i++)
    {
        tasks.push_back(Task(i));
        tasks[i].machineTime = input[i];
    }

    for(int i = 0; i < input[0].size(); i++)
        machines.push_back(Machine());
}

Controller::Controller(unsigned int machineCount, unsigned int taskCount)
{
    std::random_device rd;
    std::mt19937_64 generator(rd());
    std::uniform_int_distribution<> distribution(1,10);

    machines = std::vector<Machine>(machineCount);

    for(unsigned int i = 0; i < taskCount; i++) {
        tasks.push_back(Task(i));
        for (unsigned int j = 0; j < machineCount; j++) {
            tasks.back().machineTime.push_back(distribution(generator));
        }
    }
}

int Controller::calculateTask(std::vector<int> order)
{
    for(std::vector<int>::size_type i = 0; i < tasks.size(); i++)
    {
        for (std::vector<int>::size_type j = 0; j < machines.size(); j++) {
            if (j == 0)
                machines[j].timePassed += tasks[order[i]].machineTime[j];
            else {
                if (machines[j].timePassed < machines[j - 1].timePassed)
                    machines[j].timePassed = machines[j - 1].timePassed;

                machines[j].timePassed += tasks[order[i]].machineTime[j];
            }
        }
    }

    return machines.back().timePassed;
}

void Controller::resetMachines()
{
    for(auto& machine : machines)
        machine.timePassed = 0;
}

void Controller::permutationOrder()
{
    std::vector<std::vector<int> > permutation = scheduler.permutations(machines.size());
    int cmax;

    for(auto& perm : permutation) {
        std::cout << "Order: [";
        for (auto& val : perm) {
            std::cout<<val<<" ";
        }

        cmax = calculateTask(perm);
        std::cout<<"],   Cmax = "<<cmax<<std::endl;
        resetMachines();
    }
}

void Controller::johnsonOrder()
{
    std::vector<int> order = scheduler.johnsonsRule(tasks);

    std::cout << "Order: [";
    for (auto& val : order) {
        std::cout<<val<<" ";
    }

    std::cout<<"],   Cmax = "<<calculateTask(order)<<std::endl;
    resetMachines();
}