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
    std::ifstream file("neh.data.txt");
    std::ofstream ofile(std::string("output.data"));
    int taskCount = -1, machineCount = -1,val,nehResult;
    std::vector<int> machineTime;

    std::string dummy;

    ofile<<"NEH Cmax:Annealing Cmax:Annealing time\n";

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

        for(auto& elem : nehOrder)
            elem--;

        /*
         *                                                  TEST SECTION
         */

        std::cout<<x<<std::endl;

        Controller controller(input);
        controller.setAlgorithm(ANNEALING);
        controller.setParams(SWAP,false,ALPHA,STANDARD,nehOrder,RANDOM,NO,0.9);
        ofile<<nehResult<<","<<controller.calculateCmax(controller.order());
	//        ofile<<","<<Tester::functionTime(controller,&Controller::order)<<std::endl;
    }



    return 0;
}
