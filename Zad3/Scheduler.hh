//
// Created by mrhowever on 10.03.19.
//

#ifndef SPD3_SCHEDULER_HH
#define SPD3_SCHEDULER_HH

#include <vector>
#include "Task.hh"
#include "OrderingAlgorithm.hh"
#include <memory>

typedef std::vector<int> Order;

enum ExtendedNEHType : unsigned int {LONGEST, SUM, BIGGEST, REMOVAL};
//enum OrderingAlgorithm : unsigned int {PERMUTATION,JOHNSON,NEH,ENEHL,ENEHS,ENEHB,ENEHR,ANNEAL};

class Scheduler {
public:
    std::unique_ptr<OrderingAlgorithm> algorithm;
    Order order(Tasks&);

    std::vector<Order> permutations(int);
};


#endif //SPD3_SCHEDULER_HH
