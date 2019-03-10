//
// Created by mrhowever on 09.03.19.
//

#ifndef SPD1_CONTROLLER_HH
#define SPD1_CONTROLLER_HH

#include <vector>
#include "Machine.hh"
#include "Task.hh"
#include "Scheduler.hh"

class Controller {

    Scheduler scheduler;

public:

    Controller(std::vector<std::vector<int> >);
    Controller(unsigned int, unsigned int);
    int calculateTask(std::vector<int>);
    void johnsonOrder();
    void permutationOrder();
    void resetMachines();

    std::vector<Machine> machines;
    std::vector<Task> tasks;

};


#endif //SPD1_CONTROLLER_HH
