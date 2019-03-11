//
// Created by mrhowever on 09.03.19.
//

#ifndef SPD1_TASK_HH
#define SPD1_TASK_HH

#include <vector>

//Podstawowa klasa zadania, posiada pole z identyfikatorem danego zadania oraz
//wektor czasow wykonania na poszczegolnych maszynach

class Task {
public:
    int taskID;
    std::vector<int> machineTime;

    Task(int id) : taskID(id) {}
};


#endif //SPD1_TASK_HH
