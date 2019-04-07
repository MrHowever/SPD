//
// Created by mrhowever on 29.03.19.
//

#include "SimulatedAnnealing.hh"
#include "Controller.hh"
#include <algorithm>
#include <numeric>
#include <random>
#include <cmath>

Order SimulatedAnnealing::order(Tasks& tasks)
{
    Order order = startingType == RANDOM ? firstOrder(tasks.size()) : startingPoint;
    double temp = START_TEMP, randVal;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0,1);

    Order bestOrder = order;
    int bestCmax = cost(order,tasks);

    int j = 0;
    while(temp > FINISH_TEMP) {
        for (int i = 0; i < ITERATIONS; i++) {
            Order newOrder = neighbour(order, neighbourType);
            int orderCmax = cost(order,tasks);
            int newOrderCmax = cost(newOrder,tasks);

            if(orderCmax < bestCmax) {
                bestOrder = order;
                bestCmax = orderCmax;
            }

            randVal = dist(gen);
            if(restart(i,bestCmax,newOrderCmax,restartType) && restartType != NO) {
                order = bestOrder;
            }
            else if(probability(orderCmax, newOrderCmax, temp, probabilityType, requireDiff) >= randVal) {
                order = newOrder;
            }


        }

        j++;
        temp = temperature(j, temp, coolingType);
    }

    return bestOrder;
}

bool SimulatedAnnealing::restart(int i, int currentCmax, int bestCmax, RestartingAlgorithm alg)
{
    switch(alg)
    {
        case FIXED:
            return !(i % STEPS);

        case ENERGYDIFF:
            return (currentCmax - bestCmax) > MAX_ENERGY_DIFFERENCE;
    }
}

void SimulatedAnnealing::setParams(NeighbourAlgorithmType ntype, bool reqDiff,
                                    CoolingAlgorithm ctype, ProbabilityAlgorithm ptype,
                                    Order startPoint, StartingPointType stype, RestartingAlgorithm  rtype, double a)
{
    neighbourType = ntype;
    requireDiff = reqDiff;
    coolingType = ctype;
    probabilityType = ptype;
    startingPoint = startPoint;
    startingType = stype;
    restartType = rtype;
    alpha = a;
}

Order SimulatedAnnealing::neighbour(Order order, NeighbourAlgorithmType type)
{
    switch(type)
    {
        case SWAP:
            return swap(order);

        case RAND:
            return randPerm(order);

        case INSERT:
            return insert(order);
    }
}

Order SimulatedAnnealing::insert(Order order)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> dist(0,order.size()-1);
    int randVal = dist(gen);

    int taskID = order[randVal];
    order.erase(order.begin()+randVal);

    dist = std::uniform_int_distribution<unsigned int>(0,order.size()-1);
    randVal = dist(gen);
    order.insert(order.begin() + randVal,taskID);

    return order;
}

Order SimulatedAnnealing::swap(Order order)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> dist(0,order.size()-2);
    int randVal = dist(gen);

    std::swap(order[randVal],order[randVal+1]);

    return order;
}

Order SimulatedAnnealing::randPerm(Order order)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> dist(1,PERMUTATIONS);
    int randVal = dist(gen);

    for(int i = 0; i < randVal; i++) {
        std::next_permutation(order.begin(),order.end());
    }

    return order;
}


double SimulatedAnnealing::probability(int currentCost, int newCost, double temperature, ProbabilityAlgorithm alg, bool requireDiff)
{
    if(requireDiff && currentCost == newCost)
        return false;

    switch(alg)
    {
        case IGNOREBETTER:      //TODO
            return std::exp(-(newCost - currentCost) / temperature);

        case STANDARD:
            return newCost < currentCost ? 1.0 : std::exp(-(newCost - currentCost) / temperature);

    }
}

double SimulatedAnnealing::temperature(int i, double temperature, CoolingAlgorithm alg)
{
    switch(alg)
    {
        case ITERATION:
            return i == 0 ? START_TEMP : START_TEMP - i * (START_TEMP - FINISH_TEMP) / ITERATIONS;

        case ALPHA:
            return i == 0 ? START_TEMP : temperature*alpha;
    }
}

Order SimulatedAnnealing::firstOrder(unsigned int n)
{
    Order order(n);
    std::iota(order.begin(), order.end(),0);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> dist(1,10000);
    int randVal = dist(gen);

    for(int i = 0; i < randVal; i++) {
        std::next_permutation(order.begin(), order.end());
    }

    return order;
}

int SimulatedAnnealing::cost(Order order, Tasks tasks)
{
    Controller controller(tasks);
    return controller.calculateCmax(order);
}