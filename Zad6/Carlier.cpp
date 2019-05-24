//
// Created by mrhowever on 13.05.19.
//

#include "Carlier.hh"
#include "Schrage.hh"
#include <limits>
#include <tuple>
#include <iostream>
#include <thread>

int Carlier::C_pi(Tasks order, int n)
{
    int timePassed = 0;

    for(int i = 0; i <= n; i++) {
        if(timePassed < order[i].r) {
            timePassed += (order[i].r - timePassed);
        }

            timePassed += order[i].p;
    }

    return timePassed;
}

int Carlier::b(Tasks tasks, int Cmax)
{
    for(int i = tasks.size() - 1; i >= 0; i--) {
        if((C_pi(tasks,i) + tasks[i].q) == Cmax) {
            return i;
        }
    }

    return -1;
}

int Carlier::a(Tasks tasks, int b, int Cmax)
{
    for(int i = 0, sum = 0; i < tasks.size(); i++) {
        for(int j = i; j <= b; j++) {
            sum += tasks[j].p;
        }

        if((tasks[i].r + sum + tasks[b].q) == Cmax) {
            return i;
        }
        else {
            sum = 0;
        }
    }

    return -1;
}

int Carlier::c(Tasks tasks, int a, int b)
{
    for(int i = b-1; i >= a; i--) {
        if(tasks[i].q < tasks[b].q) {
            return i;
        }
    }

    return -1;
}

void Carlier::order(unsigned int& UB, Tasks& tasks)
{
    Schrage schrage(tasks);
    std::pair<Tasks,unsigned int> result = schrage.nlognOrder();
    unsigned int U = result.second;
    unsigned int LB = 0;
    int a = tasks.size(), b = -1, c = -1;
    unsigned int r_prim = std::numeric_limits<unsigned int>::max(),
                 q_prim = std::numeric_limits<unsigned int>::max(),
                 p_prim = 0,
                 h_prim = 0,
                 h_prim2 = 0,
                 saved_r = 0,
                 saved_q = 0,
                 r_prim2,
                 p_prim2,
                 q_prim2;

    tasks = result.first;

    schrage.tasks = tasks;
    LB = schrage.nlognPtmnOrder().second;
    if(LB >= UB) {
        return;
    }

    if(U < UB) {
        UB = U;
        bestPermutation = tasks;
    }

    b = this->b(tasks,U);
    a = this->a(tasks,b,U);
    c = this->c(tasks,a,b);

    if(c == -1) {
        return;
    }


    for(int i = c+1; i <= b; i++) {
        if(tasks[i].r < r_prim)
            r_prim = tasks[i].r;
        if(tasks[i].q < q_prim)
            q_prim = tasks[i].q;

        p_prim += tasks[i].p;
    }


    h_prim = r_prim+p_prim+q_prim;

    //Elimination tests
    for(int i = 0; i < tasks.size(); i++) {
        if( (i <= c || i > b) && tasks[i].p > (UB-h_prim)) {
            if(tasks[i].r+tasks[i].p+p_prim+tasks[b].q >= UB) {
                tasks[i].r = std::max(tasks[i].r,r_prim+p_prim);
            }

            if(r_prim+tasks[i].p+p_prim+tasks[i].q >= UB) {
                tasks[i].q = std::max(tasks[i].q,q_prim+p_prim);
            }
        }
    }

    // h_prim U {c}
    r_prim2 = tasks[c].r < r_prim ? tasks[c].r : r_prim;
    q_prim2 = tasks[c].q < q_prim ? tasks[c].q : q_prim;
    p_prim2 = p_prim + tasks[c].p;
    h_prim2 = r_prim2+q_prim2+p_prim2;

    saved_r = tasks[c].r;
    tasks[c].r = std::max(tasks[c].r,r_prim+p_prim);

    schrage.tasks = tasks;
    LB = schrage.nlognPtmnOrder().second;
    LB = std::max(std::max(h_prim,h_prim2),LB);

    if(LB < UB)
        order(UB,tasks);

    tasks[c].r = saved_r;

    saved_q = tasks[c].q;
    tasks[c].q = std::max(tasks[c].q,q_prim+p_prim);

    schrage.tasks = tasks;
    LB = schrage.nlognPtmnOrder().second;
    LB = std::max(std::max(h_prim,h_prim2),LB);

    if(LB < UB)
        order(UB,tasks);

    tasks[c].q = saved_q;
}

int Carlier::Cmax(Tasks tasks)
{
    int Cmax = 0;

    for(int i = 0; i < tasks.size(); i++) {
        if(C_pi(tasks,i) + tasks[i].q > Cmax) {
            Cmax = C_pi(tasks,i) + tasks[i].q;
        }
    }

    return Cmax;
}
