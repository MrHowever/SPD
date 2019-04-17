//
// Created by mrhowever on 16.04.19.
//

#include "Schrage.hh"
#include "Heap.hh"
#include <numeric>
#include <iostream>

std::pair<Tasks,unsigned int> Schrage::order()
{
    Tasks Ng, Nn = tasks, o;
    unsigned int t = Nn[smallestR(Nn)].r;
    Task j;
    unsigned int Cmax = 0;

    int i = 1;
    while(!Ng.empty() || !Nn.empty()) {
        while(!Nn.empty() && Nn[smallestR(Nn)].r <= t) {
            unsigned int smallestRIdx = smallestR(Nn);
          j = Nn[smallestRIdx];
          Ng.push_back(j);
          Nn.erase(Nn.begin() + smallestRIdx);
        }

        if(Ng.empty()) {
            t = Nn[smallestR(Nn)].r;
        }
        else {
            unsigned int biggestQIdx = biggestQ(Ng);
            j = Ng[biggestQIdx];
            Ng.erase(Ng.begin() + biggestQIdx);
            o.push_back(j);
            t += j.p;
            Cmax = std::max(Cmax,t+j.q);
        }
    }

    return std::pair<Tasks,unsigned int>(o,Cmax);
}

std::pair<Tasks,unsigned int> Schrage::nlognOrder()
{
    Heap Nn(tasks,MINHEAP);
    Heap Ng(Tasks(),MAXHEAP);
    Tasks o;
    unsigned int t = Nn.heap[0].r;
    Task j;
    unsigned int Cmax = 0;

    while(!Ng.empty() || !Nn.empty()) {
        while(!Nn.empty() && Nn.heap[0].r <= t) {
            j = Nn.getRoot();
            Ng.insert(j);
        }

        if(Ng.empty()) {
            t = Nn.heap[0].r;
        }
        else {
            j = Ng.getRoot();
            o.push_back(j);
            t += j.p;
            Cmax = std::max(Cmax,t+j.q);
        }
    }

    return std::pair<Tasks,unsigned int>(o,Cmax);
}


std::pair<Tasks,unsigned int> Schrage::ptmnOrder()
{
    Tasks Ng, Nn = tasks, o;
    unsigned int t = Nn[smallestR(Nn)].r;
    Task j,l(0,0,std::numeric_limits<unsigned int>::max(),0);
    unsigned int Cmax = 0;

    while(!Ng.empty() || !Nn.empty()) {
        while(!Nn.empty() && Nn[smallestR(Nn)].r <= t) {
            unsigned int smallestRIdx = smallestR(Nn);
            j = Nn[smallestRIdx];
            Ng.push_back(j);
            Nn.erase(Nn.begin() + smallestRIdx);

            if (j.q > l.q) {
                l.p = t - j.r;
                t = j.r;

                if (l.p > 0) {
                    Ng.push_back(l);
                }
            }
        }

        if(Ng.empty()) {
            t = Nn[smallestR(Nn)].r;
        }
        else {
            unsigned int biggestQIdx = biggestQ(Ng);
            j = Ng[biggestQIdx];
            Ng.erase(Ng.begin() + biggestQIdx);
            o.push_back(j);
            t += j.p;
            Cmax = std::max(Cmax,t+j.q);
            l = j;
        }
    }

    return std::pair<Tasks,unsigned int>(o,Cmax);
}


std::pair<Tasks,unsigned int> Schrage::nlognPtmnOrder(){
    Heap Nn(tasks,MINHEAP);
    Heap Ng(Tasks(),MAXHEAP);
    Tasks o;
    unsigned int t = Nn.heap[0].r;
    Task j,l(0,0,std::numeric_limits<unsigned int>::max(),0);
    unsigned int Cmax = 0;

    while(!Ng.empty() || !Nn.empty()) {
        while(!Nn.empty() && Nn.heap[0].r <= t) {
            j = Nn.getRoot();
            Ng.insert(j);

            if (j.q > l.q) {
                l.p = t - j.r;
                t = j.r;

                if (l.p > 0) {
                    Ng.insert(l);
                }
            }
        }

        if(Ng.empty()) {
            t = Nn.heap[0].r;
        }
        else {
            j = Ng.getRoot();
            o.push_back(j);
            t += j.p;
            Cmax = std::max(Cmax,t+j.q);
            l = j;
        }
    }

    return std::pair<Tasks,unsigned int>(o,Cmax);
}

unsigned int Schrage::smallestR(const Tasks& Nn)
{
    unsigned int idx = 0;
    for(unsigned int i = 0; i < Nn.size(); i++) {
        if(Nn[i].r < Nn[idx].r)
            idx = i;
    }

    return idx;
}

unsigned int Schrage::biggestQ(const Tasks& Ng)
{
    unsigned int idx = 0;
    for(unsigned int i = 0; i < Ng.size(); i++) {
        if(Ng[i].q > Ng[idx].q)
            idx = i;
    }

    return idx;
}