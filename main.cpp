#include <iostream>
#include "Controller.hh"

int main()
{
    std::vector<int> vec1 = {4,7};
    std::vector<int> vec2 = {9,2};
    std::vector<int> vec3 = {5,2};

    std::vector<std::vector<int> > input;
    input.push_back(vec1);
    input.push_back(vec2);
    input.push_back(vec3);

    Controller controller(input);

    std::cout<<"Tasks = "<<controller.tasks.size()<<", Machines = "<<controller.machines.size()<<std::endl;

    for(int i = 0; i < controller.tasks.size(); i++)
    {
        std::cout<<"Task "<<i<<": ";
        for (int j = 0; j < controller.machines.size(); j++)
            std::cout <<controller.tasks[i].machineTime[j]<<", ";
        std::cout<<std::endl;
    }

    controller.johnsonOrder();

    /*
    std::vector<int> order = {2,1,0};

    controller.calculateTask(order);

    for(std::vector<Machine>::size_type i = 0; i < controller.machines.size(); i++)
        std::cout<<"Machine "<<i<<": Time = "<<controller.machines[i].timePassed<<std::endl;
*/


    return 0;
}