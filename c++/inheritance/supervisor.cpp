//
// Created by moonmaster on 3/9/16.
//

#include "supervisor.h"

Supervisor::Supervisor(std::string theName, float thePayRate, std::string department) : Manager(theName, thePayRate, true){ salaried = true; };

void Supervisor::setDept(std::string d)
{
    department = d;
}

std::string Supervisor::getDept()
{
    return department;
}
