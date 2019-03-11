//
// Created by mrhowever on 09.03.19.
//

#include "Controller.hh"
#include "Scheduler.hh"
#include <iostream>
#include <random>
#include <string>
#include <fstream>


Controller::Controller(std::vector<std::vector<int> > input)
{
    init(input);
}

Controller::Controller(std::string filename)
{
    init(readFile(filename));
}

std::vector<std::vector<int> > Controller::readFile(std::string filename)
{
    std::ifstream file(filename);
    int taskCount, machineCount,val;
    std::vector<int> machineTime;
    std::vector<std::vector<int> > input;

    file>>taskCount>>machineCount;

    for(int i = 0; i < taskCount; i++) {
        for (int j = 0; j < machineCount; j++) {
            if(!(file >> val)) {
                std::cerr << "Invalid file format\n" << std::endl;
            }

            machineTime.push_back(val);
        }

        input.push_back(machineTime);
        machineTime.clear();
    }

    return input;
}

void Controller::init(std::vector<std::vector<int> > input)
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

std::vector<std::vector<int> > Controller::permutationOrder()
{
    std::vector<std::vector<int> > permutation = scheduler.permutations(tasks.size());
    int cmax;

    /*
    for(auto& perm : permutation) {
        std::cout << "Order: [";
        for (auto& val : perm) {
            std::cout<<val<<" ";
        }

        cmax = calculateTask(perm);
        std::cout<<"],   Cmax = "<<cmax<<std::endl;
        resetMachines();
    }
*/
    return permutation;
}

std::vector<int> Controller::johnsonOrder()
{
    std::vector<int> order = scheduler.johnsonsRule(tasks);
    resetMachines();

    return order;
}