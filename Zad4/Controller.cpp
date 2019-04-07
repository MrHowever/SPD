//
// Created by mrhowever on 09.03.19.
//

#include "Controller.hh"
#include "Scheduler.hh"
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <chrono>

//Konstruktor odczytujacy dane z wektorow
Controller::Controller(DataArray input)
{
    init(input);
}

//Konstruktor odczytujacy dane z pliku
Controller::Controller(std::string filename)
{
    init(readFile(filename));
}

Controller::Controller(std::vector<Task> inputTasks) : tasks(inputTasks), machines(inputTasks[0].machineTime.size())
{

}


Order Controller::order()
{
    return scheduler.order(tasks);
}
void Controller::setAlgorithm(AlgorithmType type)
{
    scheduler.setAlgorithm(type);
}


//Funkcja czytajaca plik w formacie takim jak ta000
DataArray Controller::readFile(std::string filename)
{
    std::ifstream file(filename);
    int taskCount, machineCount,val;
    std::vector<int> machineTime;
    DataArray input;

    file>>taskCount>>machineCount;

    for(int i = 0; i < taskCount; i++) {
        for (int j = 0; j < machineCount; j++) {
            if(!(file >> val)) {
                std::cerr << "Invalid file format\n" << std::endl;
            }

            machineTime.push_back(val);
        }

        input.push_back(machineTime);
        machineTime.clear();
    }

    return input;
}

void Controller::setParams(NeighbourAlgorithmType ntype, bool reqDiff, CoolingAlgorithm ctype,
                            ProbabilityAlgorithm ptype, Order startPoint, StartingPointType stype,
                            RestartingAlgorithm rtype, double alpha)
{
    scheduler.algorithm->setParams(ntype,reqDiff,ctype,ptype,startPoint,stype,rtype,alpha);
}

//Funkcja wypelniajaca wektory zadan i maszyn podanymi jako parametr wartosciami
void Controller::init(DataArray input)
{
    for(std::vector<int>::size_type i = 0; i < input.size(); i++) {
        tasks.push_back(Task(i));
        tasks[i].machineTime = input[i];
    }

    for(int i = 0; i < input[0].size(); i++)
        machines.push_back(Machine());
}

//Konstruktor tworzacy zadana ilosc maszyn i zadan z losowym czasem wykonania
Controller::Controller(unsigned int machineCount, unsigned int taskCount)
{
    std::random_device rd;
    std::mt19937_64 generator(rd());
    std::uniform_int_distribution<> distribution(1,10);

    machines = std::vector<Machine>(machineCount);

    for(unsigned int i = 0; i < taskCount; i++) {
        tasks.push_back(Task(i));
        for (unsigned int j = 0; j < machineCount; j++) {
            tasks.back().machineTime.push_back(distribution(generator));
        }
    }
}

//Funkcja obliczajaca czas wykonania zadan Cmax dla podanej jako parametr kolejnosci
int Controller::calculateCmax(Order order)
{
    for(std::vector<int>::size_type i = 0; i < order.size(); i++)
    {
        for (std::vector<int>::size_type j = 0; j < machines.size(); j++) {
            if (j == 0)
                machines[j].timePassed += tasks[order[i]].machineTime[j];
            else {
                if (machines[j].timePassed < machines[j - 1].timePassed)
                    machines[j].timePassed = machines[j - 1].timePassed;

                machines[j].timePassed += tasks[order[i]].machineTime[j];
            }
        }
    }

    return machines.back().timePassed;
}


//Funkcja resetujaca czas zliczony na wszystkich maszynach, by kolejne obliczenia czasu na tych samych maszynach
//sie nie kumulowaly
void Controller::resetMachines()
{
    for(auto& machine : machines)
        machine.timePassed = 0;
}