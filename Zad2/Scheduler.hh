//
// Created by mrhowever on 10.03.19.
//

#ifndef SPD3_SCHEDULER_HH
#define SPD3_SCHEDULER_HH

#include <vector>
#include "Task.hh"

typedef std::vector<int> Order;

enum ExtendedNEHType : unsigned int {LONGEST, SUM, BIGGEST, REMOVAL};
enum OrderingAlgorithm : unsigned int {PERMUTATION,JOHNSON,NEH,ENEHL,ENEHS,ENEHB,ENEHR,ANNEAL};

//Klasa obliczajaca kolejnosc zadan zgodnie z regula Johnsona lub wszystkie permutacje zadan

class Scheduler {
public:
    std::vector<Order> permutations(int);
    Order johnsonsRule(std::vector<Task>&);
    Order johnsonsRule2(std::vector<Task>);
    Order johnsonsRule3(std::vector<Task>);
    Order nehOrder(std::vector<Task>,bool);

    static bool comparePriorities(std::pair<int,int>&,std::pair<int,int>&);

    std::vector<std::vector<int> > longestOutPath(std::vector<Task>&,Order);
    std::vector<std::vector<int> > longestInPath(std::vector<Task>&,Order);

    long lowestCmaxIndex(std::vector<std::vector<int> >,std::vector<std::vector<int> >, Task);
private:
    long extendNEHPickIdx(Order&,std::vector<Task>,ExtendedNEHType,long);
    int bestRemovalIdx(Order,std::vector<Task>,long);

};


#endif //SPD3_SCHEDULER_HH
