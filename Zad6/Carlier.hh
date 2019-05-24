//
// Created by mrhowever on 13.05.19.
//

#ifndef ZAD5_CARLIER_HH
#define ZAD5_CARLIER_HH

#include "Task.hh"
#include "FileReader.hh"
#include <mutex>

class Carlier {

public:
    std::mutex permutation_lock;
    std::mutex tasks_lock;
    Tasks bestPermutation;
    Carlier() {}
    void order(unsigned int&,Tasks&);
    int C_pi(Tasks,int);
    int b(Tasks,int);
    int a(Tasks,int,int);
    int c(Tasks,int,int);
    int Cmax(Tasks);
};


#endif //ZAD5_CARLIER_HH
