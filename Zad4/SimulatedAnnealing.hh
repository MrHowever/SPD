//
// Created by mrhowever on 29.03.19.
//

#ifndef SPD3_SIMULATEDANNEALING_HH
#define SPD3_SIMULATEDANNEALING_HH

#include "OrderingAlgorithm.hh"
#include <vector>

#define START_TEMP 1
#define FINISH_TEMP 0.0001
#define ITERATIONS 100
#define PERMUTATIONS 1000
#define STEPS 5
#define MAX_ENERGY_DIFFERENCE 100

class SimulatedAnnealing : public OrderingAlgorithm {
public:
    Order order(Tasks&);

    SimulatedAnnealing(double a) : neighbourType(SWAP), coolingType(ITERATION),
                                    probabilityType(STANDARD), startingType(RANDOM),
                                    requireDiff(false), startingPoint(std::vector<int>()), restartType(NO), alpha(a) {}

    void setParams(NeighbourAlgorithmType,bool,CoolingAlgorithm,ProbabilityAlgorithm,
                   Order, StartingPointType, RestartingAlgorithm, double);

    double alpha;
private:
    NeighbourAlgorithmType neighbourType;
    CoolingAlgorithm coolingType;
    ProbabilityAlgorithm probabilityType;
    StartingPointType startingType;
    RestartingAlgorithm restartType;
    bool requireDiff;
    Order startingPoint;

    double probability(int,int,double,ProbabilityAlgorithm = STANDARD, bool = false);
    double temperature(int,double,CoolingAlgorithm = ITERATION);
    Order firstOrder(unsigned int);
    int cost(Order,Tasks);
    bool restart(int,int,int,RestartingAlgorithm = FIXED);

    Order neighbour(Order, NeighbourAlgorithmType = SWAP);
    Order swap(Order);
    Order randPerm(Order);
    Order insert(Order);

};


#endif //SPD3_SIMULATEDANNEALING_HH
