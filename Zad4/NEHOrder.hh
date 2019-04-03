//
// Created by mrhowever on 29.03.19.
//

#ifndef SPD3_NEHORDER_HH
#define SPD3_NEHORDER_HH

#include "OrderingAlgorithm.hh"

enum ExtendedNEHType : unsigned int {NONE,LONGEST, SUM, BIGGEST, REMOVAL};

class NEHOrder : public OrderingAlgorithm {
public:
    NEHOrder(ExtendedNEHType type = NONE, bool acc = true) : type(type), acceleration(acc) {}

private:
    ExtendedNEHType type;
    bool acceleration;

    Order order(Tasks&);

    static bool comparePriorities(std::pair<int,int>&,std::pair<int,int>&);

    Order extendedNEH(Order&, Tasks&,long);

    std::vector<std::vector<int> > longestOutPath(Tasks&,Order);
    std::vector<std::vector<int> > longestInPath(Tasks&,Order);

    long lowestCmaxIndex(std::vector<std::vector<int> >,std::vector<std::vector<int> >, Task);
    long extendNEHPickIdx(Order&,Tasks,ExtendedNEHType,long);
    int bestRemovalIdx(Order,Tasks,long);
};


#endif //SPD3_NEHORDER_HH
