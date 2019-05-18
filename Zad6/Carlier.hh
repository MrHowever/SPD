//
// Created by mrhowever on 13.05.19.
//

#ifndef ZAD5_CARLIER_HH
#define ZAD5_CARLIER_HH

#include "Task.hh"
#include "FileReader.hh"

class Carlier {

public:
    Tasks bestPermutation;
    Carlier(Tasks tasks1) : tasks(tasks1) {}
    void order(unsigned int&);
    int C_pi(Tasks,int);
    int b(Tasks,int);
    int a(Tasks,int,int);
    int c(Tasks,int,int);
    Tasks tasks;
    int Cmax(Tasks);

};


#endif //ZAD5_CARLIER_HH
