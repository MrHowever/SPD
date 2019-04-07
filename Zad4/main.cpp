#include <iostream>
#include <fstream>
#include "Controller.hh"
#include <string>
#include <random>
#include "FlowshopGraph.hh"
#include "Tester.hh"


#include <string>

int main(int argc, char** argv)
{
/*
    for(int i = 1; i < argc; i++) {
        std::string str = argv[1];
        Controller controller(str);
        controller.setAlgorithm(Scheduler::toAlgorithmType(argv[2]));
        Order ord = controller.order();
        std::cout<<"Cmax = "<<controller.calculateCmax(ord);
    }
    */

    std::ifstream file("neh.data.txt");
    int taskCount = -1, machineCount = -1,val,nehResult;
    std::vector<int> machineTime;

    std::string dummy;

    for(int x = 0; x < 120; x++) {
        DataArray input;
        Order nehOrder;

        getline(file, dummy);                   //Read dataset ID
        file >> taskCount >> machineCount;      //Read task and machine count

        for (int i = 0; i < taskCount; i++) {   //Read the data array
            for (int j = 0; j < machineCount; j++) {
                if (!(file >> val)) {
                    std::cerr << "Invalid file format\n" << std::endl;
                }

                machineTime.push_back(val);
            }

            input.push_back(machineTime);
            machineTime.clear();
        }

        for (int i = 0; i < 3; i++)             //Skip to NEH results
            getline(file, dummy);

        file >> nehResult;                      //Read NEH Cmax

        for (int i = 0; i < taskCount; i++) {   //Read NEH order
            file >> val;
            nehOrder.push_back(val);
        }

        for (int i = 0; i < 2; i++)             //Skip to next dataset
            getline(file, dummy);

        Controller controller(input);
        controller.setAlgorithm(ANNEALING);
        std::cout<<"NEH Cmax = "<<nehResult<<" Annealing cmax = "<<controller.calculateCmax(controller.order())<<std::endl;
    }

    return 0;
}