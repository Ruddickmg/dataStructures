//
// Created by moonmaster on 3/9/16.
//

#include "manager.h"

Manager::Manager(std::string theName,
                 float thePayRate,
                 bool isSalaried)
        : Employee(theName, thePayRate)
{
    salaried = isSalaried;
}

void Manager::setSalaried(bool s)
{
    salaried = s;
}

bool Manager::getSalaried() const
{
    return salaried;
}

float Manager::pay(float hoursWorked) const
{
    if (salaried)
        return payRate;
    /* else */
    return Employee::pay(hoursWorked);
}