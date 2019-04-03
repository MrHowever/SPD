//
// Created by mrhowever on 24.03.19.
//

#ifndef SPD3_NODE_HH
#define SPD3_NODE_HH


#include <ostream>

class Node {

public:
    Node* taskSon, *taskParent;
    Node* machineSon, *machineParent;

    unsigned int task, machine;
    unsigned int timePassed;
    unsigned int taskTime;

    void operator=(const Node& node) {
        taskSon = node.taskSon;
        taskParent = node.taskParent;
        machineSon = node.machineSon;
        machineParent = node.machineParent;
        task = node.task;
        machine = node.machine;
        timePassed = node.timePassed;
        taskTime = node.taskTime;
    }

    Node(const Node& node) : taskSon(node.taskSon), taskParent(node.taskParent),
                                machineSon(node.machineSon), machineParent(node.machineParent),
                             task(node.task), machine(node.machine), timePassed(node.timePassed),
                             taskTime(node.taskTime) {}

    Node() : taskSon(nullptr), taskParent(nullptr), machineSon(nullptr), machineParent(nullptr),
             task(0), machine(0), timePassed(0), taskTime(0) {}

};

std::ostream& operator<<(std::ostream&, Node&);


#endif //SPD3_NODE_HH
