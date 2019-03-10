//
// Created by mrhowever on 10.03.19.
//

#ifndef SPD3_SCHEDULER_HH
#define SPD3_SCHEDULER_HH

#include <vector>
#include "Task.hh"

class Scheduler {
public:
    std::vector<std::vector<int> > permutations(int);
    std::vector<int> johnsonsRule(std::vector<Task>&);
    std::vector<int> johnsonsRule2(std::vector<Task>);
    std::vector<int> johnsonsRule3(std::vector<Task>);
};


#endif //SPD3_SCHEDULER_HH
