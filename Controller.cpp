//
// Created by mrhowever on 09.03.19.
//

#include "Controller.hh"
#include <iostream>

Controller::Controller(std::vector<std::vector<int> > input)
{
    for(std::vector<int>::size_type i = 0; i < input.size(); i++)
    {
        tasks.push_back(Task());
        tasks[i].machineTime = input[i];
    }

    for(int i = 0; i < input[0].size(); i++)
        machines.push_back(Machine());
}

void Controller::calculateTask(std::vector<int> order)
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

        std::cout<<"After "<<i<<" task: Machine 0 = "<<machines[0].timePassed<<", Machine 1 = "<<machines[1].timePassed<<", Machine 2 = "<<machines[2].timePassed<<std::endl;
    }
}