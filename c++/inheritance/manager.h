//
// Created by moonmaster on 3/9/16.
//

#ifndef LABS_MANAGER_H
#define LABS_MANAGER_H
#include "employee.h"

class Manager : public Employee {
public:
    Manager(std::string theName,
            float thePayRate,
            bool isSalaried
    );

    bool getSalaried() const;

    void setSalaried(bool s);

    float pay(float hoursWorked) const;

protected:
    bool salaried;
};

#endif //LABS_MANAGER_H
