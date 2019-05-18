//
// Created by mrhowever on 16.04.19.
//

#ifndef ZAD5_TASK_HH
#define ZAD5_TASK_HH


class Task {
public:

    unsigned int r,p,q,id;

    Task(unsigned int r1, unsigned int p1, unsigned int q1, unsigned int id1) : r(r1), p(p1), q(q1), id(id1) {}
    Task() : r(0), p(0), q(0), id(-1) {}
    Task(const Task& task1) : r(task1.r), p(task1.p), q(task1.q), id(task1.id) {}
    void operator=(const Task& task1)
    {
        r = task1.r;
        p = task1.p;
        q = task1.q;
        id = task1.id;
    }
};


#endif //ZAD5_TASK_HH
