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
//#include <a.out.h>

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
