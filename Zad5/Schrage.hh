//
// Created by mrhowever on 16.04.19.
//

#ifndef ZAD5_SCHRAGE_HH
#define ZAD5_SCHRAGE_HH
#include "Task.hh"
#include "FileReader.hh"

class Schrage {
    Tasks tasks;

    unsigned int smallestR(const Tasks&);
    unsigned int biggestQ(const Tasks&);

public:
    Schrage(Tasks&& tasks1) : tasks(std::move(tasks1)) {}
    std::pair<Tasks,unsigned int> order();
    std::pair<Tasks,unsigned int> nlognOrder();
    std::pair<Tasks,unsigned int> ptmnOrder();
    std::pair<Tasks,unsigned int> nlognPtmnOrder();
};


#endif //ZAD5_SCHRAGE_HH
