//
// Created by mrhowever on 29.03.19.
//

#include <chrono>
#include "Tester.hh"
#include "Controller.hh"

void Tester::printData(std::ostream& Strm, Controller& controller)
{
    Strm << "Tasks: " <<controller.tasks.size() <<", Machines: "<<controller.machines.size() << "\n";

    for(int j = 0; j <controller.tasks.size(); j++) {
        Strm  << "Task "<< j <<": ";
        for (int k = 0; k < controller.tasks[j].machineTime.size(); k++) {
            Strm << controller.tasks[j].machineTime[k] << " ";
        }

        Strm << "\n";
    }
}

void Tester::printOrder(std::ostream& Strm, Order order)
{
    Strm << "[";
    for(auto& elem : order)
        Strm << " " << elem;
    Strm << "]";
}

double Tester::functionTime(Controller& controller, Order (Controller::*orderPtr)(void))
{
    using namespace std::chrono;

    auto start = high_resolution_clock::now();
    (controller.*orderPtr)();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(start - stop);

    return duration.count();
}
