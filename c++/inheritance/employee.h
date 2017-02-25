//
// Created by moonmaster on 3/9/16.
//

#ifndef LABS_EMPLOYEE_H
#define LABS_EMPLOYEE_H
#include <string>

class Employee {
    public:
        Employee(std::string theName, float thePayRate);

        void setName(std::string n) ;
        void setPayRate(float pr);

        std::string getName() const;
        float getPayRate() const;

        float pay(float hoursWorked) const;

    protected:
        std::string name;
        float payRate;
    };



#endif //LABS_EMPLOYEE_H
