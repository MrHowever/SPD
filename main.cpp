#include <iostream>
#include <fstream>
#include "Controller.hh"
#include <string>

int main()
{
    Controller controller(std::string("text.txt"));
    //Controller controller(6,3);

    std::cout<<"Tasks = "<<controller.tasks.size()<<", Machines = "<<controller.machines.size()<<std::endl;
    for(int i = 0; i < controller.tasks.size(); i++)
    {
        std::cout<<"Task "<<i<<": ";
        for (int j = 0; j < controller.machines.size(); j++)
            std::cout <<controller.tasks[i].machineTime[j]<<", ";
        std::cout<<std::endl;
    }

    //controller.johnsonOrder();
    controller.permutationOrder();

    return 0;
}