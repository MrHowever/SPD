//
// Created by mrhowever on 29.03.19.
//

#ifndef SPD3_ORDERINGALGORITHM_HH
#define SPD3_ORDERINGALGORITHM_HH

#include <vector>
#include "Task.hh"

typedef std::vector<int> Order;
typedef std::vector<Task> Tasks;
typedef std::vector<int> Times;


class OrderingAlgorithm {
    public:
        virtual Order order(Tasks&) = 0;

};


#endif //SPD3_ORDERINGALGORITHM_HH
