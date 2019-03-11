//
// Created by mrhowever on 09.03.19.
//

#ifndef SPD1_CONTROLLER_HH
#define SPD1_CONTROLLER_HH

#include <vector>
#include "Machine.hh"
#include "Task.hh"
#include "Scheduler.hh"
#include <string>

class Controller {

    Scheduler scheduler;

    void init(std::vector<std::vector<int> >);
    std::vector<std::vector<int> > readFile(std::string);

public:

    Controller(std::vector<std::vector<int> >);
    Controller(unsigned int, unsigned int);
    Controller(std::string);

    int calculateTask(std::vector<int>);
    std::vector<int> johnsonOrder();
    std::vector<std::vector<int> > permutationOrder();
    void resetMachines();

    std::vector<Machine> machines;
    std::vector<Task> tasks;

};


#endif //SPD1_CONTROLLER_HH
