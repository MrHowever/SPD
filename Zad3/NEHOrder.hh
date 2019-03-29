//
// Created by mrhowever on 29.03.19.
//

#ifndef SPD3_NEHORDER_HH
#define SPD3_NEHORDER_HH

#include "OrderingAlgorithm.hh"

class NEHOrder : public OrderingAlgorithm {
    Order order(Tasks&);


private:
    static bool comparePriorities(std::pair<int,int>&,std::pair<int,int>&);

    std::vector<std::vector<int> > longestOutPath(Tasks&,Order);
    std::vector<std::vector<int> > longestInPath(Tasks&,Order);

    long lowestCmaxIndex(std::vector<std::vector<int> >,std::vector<std::vector<int> >, Task);
    long extendNEHPickIdx(Order&,Tasks,ExtendedNEHType,long);
    int bestRemovalIdx(Order,Tasks,long);
};


#endif //SPD3_NEHORDER_HH
