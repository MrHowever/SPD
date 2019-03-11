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

    //Controller controller(std::string("text.txt"));
    /*
     Controller controller(6,3);

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
*/
    return 0;
}