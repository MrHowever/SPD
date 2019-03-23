//
// Created by mrhowever on 10.03.19.
//

#ifndef SPD3_SCHEDULER_HH
#define SPD3_SCHEDULER_HH

#include <vector>
#include "Task.hh"

typedef std::vector<int> Order;

//Klasa obliczajaca kolejnosc zadan zgodnie z regula Johnsona lub wszystkie permutacje zadan

class Scheduler {
public:
    std::vector<Order> permutations(int);
    Order johnsonsRule(std::vector<Task>&);
    Order johnsonsRule2(std::vector<Task>);
    Order johnsonsRule3(std::vector<Task>);
};


#endif //SPD3_SCHEDULER_HH
