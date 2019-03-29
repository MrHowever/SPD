//
// Created by mrhowever on 29.03.19.
//

#include "JohnsonOrder.hh"

Order JohnsonsOrder::order(Tasks& tasks)
{
    if(tasks[0].machineTime.size() > 3) {
        std::cerr << "Invalid number of machines\n";
        return Order();
    }

    Order order = tasks[0].machineTime.size() == 2 ? johnsonsRule2(tasks) : johnsonsRule3(tasks);

    return order;
}

//Funkcja zwracajaca kolejnosc wykonania zadan zgodnie z regula Johnsona dla 3 maszyn
Order JohnsonOrder::johnsonsRule3(Tasks tasks)
{
    for(auto& task : tasks) {
        task.machineTime[0] = task.machineTime[0] + task.machineTime[1];
        task.machineTime[1] = task.machineTime[1] + task.machineTime[2];
        task.machineTime.erase(task.machineTime.begin() + 2);
    }

    return johnsonsRule2(tasks);
}

//Funkcja zwracajaca kolejnosc wykonania zadan zgodnie z regula Johnsona dla 2 maszyn
Order JohnsonOrder::johnsonsRule2(Tasks tasks)
{
    Order order(tasks.size());
    Order::iterator front = order.begin();
    Order::reverse_iterator back = order.rbegin();
    int shortestTime = std::numeric_limits<int>::max();
    int shortestTask = 1;
    int machine = 0;

    while(!tasks.empty()) {
        for (Tasks::size_type i = 0; i < tasks.size(); i++) {
            for (Times::size_type j = 0; j < tasks[i].machineTime.size(); j++) {
                if (tasks[i].machineTime[j] < shortestTime) {
                    shortestTime = tasks[i].machineTime[j];
                    shortestTask = i;
                    machine = j;
                }
            }
        }

        if(machine)
            *back++ = tasks[shortestTask].taskID;
        else
            *front++ = tasks[shortestTask].taskID;

        tasks.erase(tasks.begin() + shortestTask);
        shortestTime = std::numeric_limits<int>::max();
    }

    return order;
}