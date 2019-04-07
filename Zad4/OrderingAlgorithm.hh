//
// Created by mrhowever on 29.03.19.
//

#ifndef SPD3_ORDERINGALGORITHM_HH
#define SPD3_ORDERINGALGORITHM_HH

#include <vector>
#include "Task.hh"
//#include "SimulatedAnnealing.hh"

typedef std::vector<int> Order;
typedef std::vector<Task> Tasks;
typedef std::vector<int> Times;

enum NeighbourAlgorithmType : unsigned int {SWAP,INSERT,RAND};
enum CoolingAlgorithm : unsigned int {ALPHA,ITERATION};
enum ProbabilityAlgorithm : unsigned int {STANDARD,IGNOREBETTER};
enum StartingPointType : unsigned int {RANDOM, NEHORDER};
enum RestartingAlgorithm : unsigned int {FIXED,ENERGYDIFF,RANDOMRESTART,NO};

class OrderingAlgorithm {
    public:
        virtual Order order(Tasks&) = 0;
        virtual void setParams(NeighbourAlgorithmType,bool,CoolingAlgorithm,ProbabilityAlgorithm,
                                Order, StartingPointType, RestartingAlgorithm, double) {}


};


#endif //SPD3_ORDERINGALGORITHM_HH
