//
// Created by mrhowever on 24.03.19.
//

#include "FlowshopGraph.hh"
#include <algorithm>
#include "Tester.hh"

FlowshopGraph::FlowshopGraph(std::vector<Task> tasks, Order order) : taskCount(tasks.size())
{
    Tester::printOrder(std::cout,order);

    unsigned int machines = tasks[0].machineTime.size();
    unsigned int nodeCount = tasks.size()*machines;
    nodes = std::vector<Node>(nodeCount);

    //Create graph connections
    for(int i = 0; i < nodeCount; i++) {
        nodes[i].task = order[i%order.size()];
        nodes[i].machine = i / tasks.size();

        if (i % tasks.size() != 0)
            nodes[i].taskParent = &(nodes[i - 1]);

        if (i % tasks.size() != (tasks.size()-1))
            nodes[i].taskSon = &(nodes[i + 1]);

        if (i >= tasks.size())
            nodes[i].machineParent = &(nodes[i - tasks.size()]);

        if (i <= (nodes.size() - (tasks.size()+1)))
            nodes[i].machineSon = &(nodes[i + tasks.size()]);
    }

    //Calculate time passed
    for(auto& node : nodes) {
        int jobTime = tasks[node.task].machineTime[node.machine];

        int machineTimePassed = node.machineParent != nullptr ? node.machineParent->timePassed : 0;
        int taskTimePassed = node.taskParent != nullptr ? node.taskParent->timePassed : 0;

        int alreadyPassed = std::max(machineTimePassed,taskTimePassed);

        node.timePassed = alreadyPassed + jobTime;
        node.taskTime = jobTime;
    }
}

void FlowshopGraph::removeNonCriticalEdges()
{
    for(auto& node : nodes) {
        if(node.taskParent != nullptr && node.machineParent != nullptr) {
            if (node.taskParent->timePassed < node.machineParent->timePassed) {
                node.taskParent->taskSon = nullptr;
                node.taskParent = nullptr;
            }
            else if (node.machineParent->timePassed < node.taskParent->timePassed) {
                node.machineParent->machineSon = nullptr;
                node.machineParent = nullptr;
            }
        }

        if(node.taskSon != nullptr && node.machineSon != nullptr) {
            if (node.taskSon->timePassed < node.machineSon->timePassed) {
                node.taskSon->taskParent = nullptr;
                node.taskSon = nullptr;
            }
            else if (node.machineSon->timePassed < node.taskSon->timePassed) {
                node.machineSon->machineParent = nullptr;
                node.machineSon = nullptr;
            }
        }
    }
}

void FlowshopGraph::reverseEdges()
{
    for(int i = 0; i < nodes.size(); i++) {
        bool hasTaskParent = nodes[i].taskParent;
        bool hasMachineParent = nodes[i].machineParent;
        bool hasTaskSon = nodes[i].taskSon;
        bool hasMachineSon = nodes[i].machineSon;

        if(hasTaskParent) {
            nodes[i].taskSon = &nodes[i - 1];

            if(!hasTaskSon)
                nodes[i].taskParent = nullptr;
        }
        if(hasMachineParent) {
            nodes[i].machineSon = &nodes[i - taskCount];

            if(!hasMachineSon)
                nodes[i].machineParent = nullptr;
        }
        if(hasTaskSon) {
            nodes[i].taskParent = &nodes[i + 1];

            if(!hasTaskParent)
                nodes[i].taskSon = nullptr;
        }
        if(hasMachineSon) {
            nodes[i].machineParent = &nodes[i + taskCount];

            if(!hasMachineParent)
                nodes[i].machineSon = nullptr;
        }
    }
}

void FlowshopGraph::printGraph(std::ostream &)
{
    int i = 0;
    for(auto& node : nodes) {
        std::cout<<"Node "<<i++<<": Val = "<<node.taskTime<<"\n ";
        if(node.machineSon != nullptr)
            std::cout<<"machineSon: "<<*node.machineSon<<std::endl;
        if(node.taskSon != nullptr)
            std::cout<<"taskSon: "<<*node.taskSon<<std::endl;
        if(node.machineParent != nullptr)
            std::cout<<"machineParent: "<<*node.machineParent<<std::endl;
        if(node.taskParent != nullptr)
            std::cout<<"taskParent: "<<*node.taskParent<<std::endl;

        std::cout<<"\n\n";
    }
}

Node* FlowshopGraph::criticalPathRoot()
{
    removeNonCriticalEdges();
    reverseEdges();
    return &nodes[nodes.size()-1];
}

int FlowshopGraph::longestCriticalOperation(std::vector<Task> tasks,Order order, long ignoreIdx)
{
    Tester::printOrder(std::cout,order);

    FlowshopGraph graph(tasks,order);
    Node* root = graph.criticalPathRoot();
    std::pair<int,int> currentMax(0,0);

    graph.maxBranchVal(root,currentMax,ignoreIdx);

    return currentMax.second;
}

void FlowshopGraph::maxBranchVal(Node* node, std::pair<int,int>& currentMax, long ignoreIdx)
{
    if(node->taskSon != nullptr) {
        maxBranchVal(node->taskSon, currentMax, ignoreIdx);
    }

    if(node->machineSon != nullptr) {
        maxBranchVal(node->machineSon,currentMax,ignoreIdx);
    }

    if(node->taskTime > currentMax.first && node->task != ignoreIdx)
        currentMax = std::pair<int,int>(node->taskTime,node->task);
}

int FlowshopGraph::longestSumOfCriticalOperations(std::vector<Task> tasks,Order order, long ignoreIdx)
{
    FlowshopGraph graph(tasks,order);
    Node* root = graph.criticalPathRoot();
    std::vector<int> timeSum(tasks.size());

    graph.maxSum(root,timeSum);

    *(timeSum.begin() + ignoreIdx) = 0;

    return std::distance(timeSum.begin(), std::max_element(timeSum.begin(),timeSum.end()));
}

void FlowshopGraph::maxSum(Node* node, std::vector<int>& timeSum)
{
    if(node->taskSon != nullptr)
        maxSum(node->taskSon,timeSum);

    if(node->machineSon != nullptr)
        maxSum(node->machineSon,timeSum);

    timeSum[node->task] += node->taskTime;
}

int FlowshopGraph::mostCriticalOperations(std::vector<Task> tasks, Order order, long ignoreIdx)
{
    FlowshopGraph graph(tasks,order);
    Node* root = graph.criticalPathRoot();
    std::vector<int> taskApp(tasks.size());

    graph.maxSum(root,taskApp);

    *(taskApp.begin() + ignoreIdx) = 0;

    return (int) std::distance(taskApp.begin(), std::max_element(taskApp.begin(),taskApp.end()));
}

void FlowshopGraph::maxCount(Node* node, std::vector<int>& timeSum)
{
    if(node->taskSon != nullptr)
        maxSum(node->taskSon,timeSum);

    if(node->machineSon != nullptr)
        maxSum(node->machineSon,timeSum);

    timeSum[node->task]++;
}
