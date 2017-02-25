//
// Created by moonmaster on 5/21/16.
//

#ifndef PROJECT1_PROJECT1_H
#define PROJECT1_PROJECT1_Hi

#include <list>
#include "Job.h"
#include "BinaryHeap.h"

class Project1 {

private:
    std::list<Job> jobs;
    BinaryHeap<Job> heap;
    const int processors;
    int processes = 0;
    int id = 1;

public:
    Project1 (int p) : processors{ p }{};
    void insert (Job & job);
    void tick ();
    void add(Job job);
    void status();
};

#endif //PROJECT1_PROJECT1_H
