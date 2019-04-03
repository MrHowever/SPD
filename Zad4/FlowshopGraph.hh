//
// Created by mrhowever on 24.03.19.
//

#ifndef SPD3_FLOWSHOPGRAPH_HH
#define SPD3_FLOWSHOPGRAPH_HH

#include "Node.hh"
#include "Task.hh"
#include "Controller.hh"
#include <vector>
#include <ostream>

class FlowshopGraph {

    std::vector<Node> nodes;

public:
    FlowshopGraph(std::vector<Task>,Order);

    void printGraph(std::ostream&);
    void removeNonCriticalEdges();
    void reverseEdges();
    Node* criticalPathRoot();

    static int longestCriticalOperation(std::vector<Task>,Order,long);
    static int longestSumOfCriticalOperations(std::vector<Task>,Order,long);
    static int mostCriticalOperations(std::vector<Task>,Order,long);


private:
    int taskCount;

    void maxBranchVal(Node*,std::pair<int,int>&, long ignoreIdx);
    void maxSum(Node*, std::vector<int>&);
    void maxCount(Node*, std::vector<int>&);
};



#endif //SPD3_FLOWSHOPGRAPH_HH
