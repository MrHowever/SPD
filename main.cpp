#include <iostream>
#include <fstream>
#include "Controller.hh"
#include <string>
#include <random>

void printTest(std::ofstream& file, unsigned int machines, int tests)
{
    std::random_device rd;
    std::mt19937_64 generator(rd());
    std::uniform_int_distribution<> distribution(1,10);
    std::vector<int> order;

    if(machines > 3 ) {
        std::cerr << "Invalid machine count in test function!\n";
        return;
    }

    for(int i = 0; i < tests; i++)
    {
        Controller controller(machines,distribution(generator));

        file << "Tasks: " <<controller.tasks.size() <<", Machines: "<< controller.machines.size() << "\n";

        for(int j = 0; j < controller.tasks.size(); j++) {
            file  << "Task "<< j <<": ";
            for (int k = 0; k < controller.tasks[j].machineTime.size(); k++) {
                file << controller.tasks[j].machineTime[k] << " ";
            }

            file << "\n";
        }

        order = controller.johnsonOrder();
        file << "Johnsons order: [";
        for (auto& val : order) {
            file<<val<<" ";
        }

        file<< "] \nCmax = "<<controller.calculateTask(order);

        file << "\n\n\n";
    }
}

int main()
{
    std::ofstream file1("JohnsonsRule2Tests.txt");
    std::ofstream file2("JohnsonsRule3Tests.txt");
    std::ofstream file3("PermutationsTests.txt");

    printTest(file1,2,3);
    printTest(file2,3,3);

    std::random_device rd;
    std::mt19937_64 generator(rd());
    std::uniform_int_distribution<> distribution(1,5);
    std::vector<std::vector<int> > order;
    std::vector<int> ord;

    for(int i = 0; i < 3; i++)
    {
        Controller controller(distribution(generator),distribution(generator));

        file3 << "Tasks: " <<controller.tasks.size() <<", Machines: "<< controller.machines.size() << "\n";

        for(int j = 0; j < controller.tasks.size(); j++) {
            file3  << "Task "<< j <<": ";
            for (int k = 0; k < controller.tasks[j].machineTime.size(); k++) {
                file3 << controller.tasks[j].machineTime[k] << " ";
            }

            file3 << "\n";
        }

        order = controller.permutationOrder();
        file3 << "Permutation order:\n";

        for(int m = 0; m < order.size(); m++) {
            file3 << "[";
            for (auto &val : order[m]) {
                file3 << val << " ";
            }

            file3 << "] Cmax = " << controller.calculateTask(order[m]) << "\n";
            controller.resetMachines();
        }
        file3 << "\n\n\n";
    }

    std::string filename = "ta000";
    std::cout<<"Reading file: "<<filename<<std::endl;
    Controller controller2(filename);

    std::cout<<"Tasks = "<<controller2.tasks.size()<<", Machines = "<<controller2.machines.size()<<std::endl;
    for(int i = 0; i < controller2.tasks.size(); i++)
    {
        std::cout<<"Task "<<i<<": ";
        for (int j = 0; j < controller2.machines.size(); j++)
            std::cout <<controller2.tasks[i].machineTime[j]<<", ";
        std::cout<<std::endl;
    }

    ord = controller2.johnsonOrder();

    std::cout<<"Order: [";
    for(int i = 0; i < ord.size(); i++)
        std::cout<<ord[i]<<" ";
    std::cout<<"] , Cmax = "<<controller2.calculateTask(ord);

    order = controller2.permutationOrder();
/*
    for(int j = 0; j < order.size(); j++) {
        std::cout << "Order: [";
        for (int i = 0; i < order[j].size(); i++)
            std::cout << order[i][j] << " ";
        std::cout << "] , Cmax = " << controller2.calculateTask(order[j]);
        controller2.resetMachines();
    }*/


    return 0;
}