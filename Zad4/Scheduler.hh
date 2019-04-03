//
// Created by mrhowever on 10.03.19.
//

#ifndef SPD3_SCHEDULER_HH
#define SPD3_SCHEDULER_HH

#include <vector>
#include "Task.hh"
#include "OrderingAlgorithm.hh"
#include <memory>

enum AlgorithmType : unsigned int {JOHNSON, NEH, ENEHL, ENEHB, ENEHS, ENEHR, ANNEALING};

class Scheduler {

    std::unique_ptr<OrderingAlgorithm> algorithm;

public:
    Order order(Tasks&);
    void setAlgorithm(AlgorithmType);
    static AlgorithmType toAlgorithmType(std::string);


    std::vector<Order> permutations(int);
};


#endif //SPD3_SCHEDULER_HH
