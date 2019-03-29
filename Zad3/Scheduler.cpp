//
// Created by mrhowever on 10.03.19.
//

#include "Scheduler.hh"
#include "Task.hh"
#include "Controller.hh"
#include "FlowshopGraph.hh"
#include <algorithm>
#include <numeric>
#include <limits>
#include <iostream>
#include <algorithm>

#include "JohnsonOrder.hh"
#include "NEHOrder.hh"
#include "SimulatedAnnealing.hh"

Order Scheduler::order(Tasks& tasks)
{
    return algorithm->order(tasks);
}

void Scheduler::setAlgorithm(AlgorithmType type)
{
    switch(type) {
        case JOHNSON:
            algorithm = std::make_unique<JohnsonOrder>();
            break;

        case NEH:
            algorithm = std::make_unique<NEHOrder>();
            break;

        case ENEHL:
            algorithm = std::make_unique<NEHOrder>(LONGEST);
            break;

        case ENEHB:
            algorithm = std::make_unique<NEHOrder>(BIGGEST);
            break;

        case ENEHS:
            algorithm = std::make_unique<NEHOrder>(SUM);
            break;

        case ENEHR:
            algorithm = std::make_unique<NEHOrder>(REMOVAL);
            break;

        case ANNEALING:
            algorithm = std::make_unique<SimulatedAnnealing>();
            break;
    }
}

//Funkcja zwracajaca wektor wszystkich permutacji kolejnosci zadan dla ilosci zadan podanej jako parametr
std::vector<Order> Scheduler::permutations(int taskCount)
{
    std::vector<int> indices(taskCount);
    std::vector<Order> permutationVec;

    std::iota(indices.begin(),indices.end(),0);

    do {
        permutationVec.push_back(indices);
    } while(std::next_permutation(indices.begin(),indices.end()));

    return permutationVec;
}
