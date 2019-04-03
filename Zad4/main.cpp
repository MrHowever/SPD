#include <iostream>
#include <fstream>
#include "Controller.hh"
#include <string>
#include <random>
#include "FlowshopGraph.hh"
#include "Tester.hh"

#define TEST_COUNT 10
#include <string>

int main(int argc, char** argv)
{

    for(int i = 1; i < argc; i++) {
        std::string str = argv[1];
        Controller controller(str);
        controller.setAlgorithm(Scheduler::toAlgorithmType(argv[2]));
        Order ord = controller.order();
        std::cout<<"Cmax = "<<controller.calculateCmax(ord);
    }
    return 0;
}