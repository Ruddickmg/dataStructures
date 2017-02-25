//
// Created by moonmaster on 5/21/16.
//

#include <iostream>
#include "Job.h"

void Job::setId(int i) { id = i; }
void Job::tick(){ tic -= 1; };
const int Job::processes () const { return process; }
const int Job::ticks () const { return tic; }
const int Job::getId () const { return id; }
const std::string Job::getDescription() const { return description; }

