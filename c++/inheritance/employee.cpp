//
// Created by moonmaster on 3/9/16.
//

#include "employee.h"

Employee::Employee(std::string theName, float thePayRate)
{
    name = theName;
    payRate = thePayRate;
}

std::string Employee::getName() const
{
    return name;
}
void Employee::setName(std::string n)
{
    name = n;
}

void Employee::setPayRate(float pr)
{
    payRate = pr;
};

float Employee::getPayRate() const
{
    return payRate;
}

float Employee::pay(float hoursWorked) const
{
    return hoursWorked * payRate;
}
