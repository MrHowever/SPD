//
// Created by mrhowever on 29.03.19.
//

#ifndef SPD3_SIMULATEDANNEALING_HH
#define SPD3_SIMULATEDANNEALING_HH

#include "OrderingAlgorithm.hh"

class SimulatedAnnealing : public OrderingAlgorithm {
    Order order(Tasks&);
};


#endif //SPD3_SIMULATEDANNEALING_HH
