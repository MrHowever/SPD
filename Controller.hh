//
// Created by mrhowever on 09.03.19.
//

#ifndef SPD1_CONTROLLER_HH
#define SPD1_CONTROLLER_HH

#include <vector>
#include "Machine.hh"
#include "Task.hh"

class Controller {
public:

    Controller(std::vector<std::vector<int> >);
    void calculateTask(std::vector<int>);

    std::vector<Machine> machines;
    std::vector<Task> tasks;
};


#endif //SPD1_CONTROLLER_HH
