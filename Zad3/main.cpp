#include <iostream>
#include <fstream>
#include "Controller.hh"
#include <string>
#include <random>
#include "FlowshopGraph.hh"

#define TEST_COUNT 10

int main()
{
    Controller controller("ta000");
    controller.setAlgorithm(NEH);
    Order ord = controller.order();


    return 0;
}