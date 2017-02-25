//
// Created by moonmaster on 3/9/16.
//

#ifndef LABS_SUPERVISOR_H
#define LABS_SUPERVISOR_H


#include "manager.h"

class Supervisor : public Manager {

public:
    Supervisor(std::string theName, float thePayRate, std::string department);

    void setDept(std::string d);
    std::string getDept();

protected:
    std::string department;
};


#endif //LABS_SUPERVISOR_H
