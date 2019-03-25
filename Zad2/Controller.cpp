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
int Controller::calculateTask(Order order)
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

//Funkcja zwracajaca wszystkie mozliwe permutacje kolejnosci zadan
std::vector<Order> Controller::permutationOrder()
{
    return scheduler.permutations(tasks.size());
}

//Funkcja zwracajaca kolejnosc zadan wg zasady Johnsona
Order Controller::johnsonOrder()
{
    return scheduler.johnsonsRule(tasks);
}

//Funkcja resetujaca czas zliczony na wszystkich maszynach, by kolejne obliczenia czasu na tych samych maszynach
//sie nie kumulowaly
void Controller::resetMachines()
{
    for(auto& machine : machines)
        machine.timePassed = 0;
}

//Funkcja drukujaca ilosc zadan, maszyn oraz czasy wkonania poszczegolnych zadan na danych maszynach
void Controller::printData(std::ostream& file)
{
    file << "Tasks: " <<tasks.size() <<", Machines: "<<machines.size() << "\n";

    for(int j = 0; j <tasks.size(); j++) {
        file  << "Task "<< j <<": ";
        for (int k = 0; k < tasks[j].machineTime.size(); k++) {
            file << tasks[j].machineTime[k] << " ";
        }

        file << "\n";
    }
}

//Funkcja drukujaca przekazana jako parametr kolejnosc zadan oraz obliczony dla niej czas wykonania
void Controller::printOrder(std::ostream& file, Order order)
{
    using namespace std::chrono;

    file<<"[";
    for(int i = 0; i < order.size(); i++)
        file<<order[i]<<" ";

    auto start = high_resolution_clock::now();
    file<<"] , Cmax = "<<calculateTask(order)<<"\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    file <<"Time = "<< duration.count()<<"\n";

    resetMachines();
}

void Controller::calcTaskTime(int maxTasks)
{
    using namespace std::chrono;

    std::ofstream times("AlgorithmTimes.txt");

    for(int i = 2; i < maxTasks; i++)
    {
        auto start = high_resolution_clock::now();
        scheduler.permutations(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop-start);
        times << duration.count() <<", ";

        Controller temp(2,i);
        start = high_resolution_clock::now();
        temp.johnsonOrder();
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop-start);
        times << duration.count() <<", ";

        Controller temp2(3,i);
        start = high_resolution_clock::now();
        temp2.johnsonOrder();
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop-start);
        times << duration.count() <<"\n";
    }
}

void Controller::permVsJohnTest() {
    std::ofstream john2out("PermutationVsJohn2Compare.txt");
    std::ofstream john3out("PermutationVsJohn3Compare.txt");
    int tasks = 8;

    for (int j = 0; j < 50; j++) {
        Controller john2(2, tasks);
        Controller john3(3, tasks);

        Order john2order = john2.johnsonOrder();
        Order john3order = john3.johnsonOrder();
        std::vector<Order> perm2order = john2.permutationOrder();
        std::vector<Order> perm3order = john3.permutationOrder();

        int cmaxjohn2 = john2.calculateTask(john2order);
        john2.resetMachines();
        int cmaxjohn3 = john3.calculateTask(john3order);
        john3.resetMachines();

        int better = 0, worse = 0;

        for (int i = 0; i < perm2order.size(); i++) {
            john2.resetMachines();
             if (john2.calculateTask(perm2order[i]) < cmaxjohn2)
                better++;
            else
                worse++;

            john2.resetMachines();
        }

        john2out << better << ", " << worse << "\n";

        better = 0;
        worse = 0;
        for (int i = 0; i < perm3order.size(); i++) {
            if (john3.calculateTask(perm3order[i]) < cmaxjohn3)
                better++;
            else
                worse++;
            john3.resetMachines();
        }

        john3out << better << ", " << worse << "\n";
    }
}

Order Controller::nehOrder(bool acceleration)
{
    return scheduler.nehOrder(tasks,acceleration);
}
