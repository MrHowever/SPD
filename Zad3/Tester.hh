//
// Created by mrhowever on 29.03.19.
//

#ifndef SPD3_TESTER_HH
#define SPD3_TESTER_HH

#include <iostream>
#include "Controller.hh"

class Tester {
    public:
    void printData(std::ostream&,Controller&);
    void printOrder(std::ostream&, Order);
    double functionTime(Controller&,Order (Controller::*)());
};


#endif //SPD3_TESTER_HH
