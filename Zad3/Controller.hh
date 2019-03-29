//
// Created by mrhowever on 09.03.19.
//

#ifndef SPD1_CONTROLLER_HH
#define SPD1_CONTROLLER_HH

#include <vector>
#include "Machine.hh"
#include "Task.hh"
#include "Scheduler.hh"
#include <string>
#include <iostream>

typedef std::vector<std::vector<int> > DataArray;
typedef std::vector<int> Order;

//Glowna klasa zarzadzajaca pobieraniem/generacja danych i obliczaniem czasow wykonania dla
//otrzymanych kolejnosci

class Controller {

    Scheduler scheduler;

    void init(DataArray);
    DataArray readFile(std::string);

public:

    Controller(DataArray);
    Controller(unsigned int, unsigned int);
    Controller(std::string);
    Controller(std::vector<Task>);

    Order order();
    void setAlgorithm(AlgorithmType);
    int calculateCmax(Order);

    void resetMachines();

    std::vector<Machine> machines;
    std::vector<Task> tasks;
};


#endif //SPD1_CONTROLLER_HH
