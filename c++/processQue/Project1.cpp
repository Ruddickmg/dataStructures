#include <iostream>
#include "Project1.h"

void Project1::insert(Job & job) {
    job.setId(id++);
    if(job.ticks() > 0 && job.processes() <= processors)
        heap.push(job);
    else std::cout << std::endl << " - Not enough processors are available to process this job, please enter a number between 1 and " << processors << " when prompted to input the number of processors." << std::endl;
}

void Project1::tick() {

    std::list<Job>::iterator job = jobs.begin();

    while (job != jobs.end()) {

        job->tick();

        if (job->ticks() < 1) {

            processes -= job->processes();
            std::cout << std::endl << std::endl << "finished: " << *job << std::endl;
            job = jobs.erase(job);

        } else job++;
    }

    if(heap.size() && processors - processes >= heap.min().processes())
        add(heap.pop());
}

void Project1::add(Job job) {
    processes += job.processes();
    jobs.push_back(job);
}

void Project1::status() {

    int i = 1;
    std::cout << "------------- status ------------------" << std::endl << std::endl;

    if(!jobs.size()) std::cout << "No running Jobs." << std::endl;

    else for (std::list<Job>::iterator job = jobs.begin(); job != jobs.end(); job++)
        std::cout << i++ << ": " << *job << std::endl;
}

