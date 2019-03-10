//
// Created by mrhowever on 09.03.19.
//

#ifndef SPD1_TASK_HH
#define SPD1_TASK_HH

#include <vector>

class Task {
public:
    int taskID;
    std::vector<int> machineTime;

    Task(int id) : taskID(id) {}
};


#endif //SPD1_TASK_HH
