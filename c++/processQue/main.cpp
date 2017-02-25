#include <iostream>
#include "Project1.h"

using namespace std;

void invalid() { cout << endl << " - Input must be an integer, exiting program." << endl << endl; }
bool minMet(int input, std::string name) {
    if(input < 1)
        cout << endl << " - Must enter one or more " << name << endl;
    else return true;
}

int main() {

    int processors, processes, ticks;
    std::string description;

    cout << endl << "---------- begin project ---------" << endl << endl;
    cout << "Enter the amount of processors to be made available: ";
    cin >> processors;

    if(cin.fail()){ invalid(); return 0; }
    if(!minMet(processors, "processors")) return 0;

    Project1 project { processors };

    while (description.compare("exit")) {

        cout << endl << "--------- create a new job --------" << endl << endl;
        cout << "Enter a job description for a new job or \"tick\" or \"continue\" to continue existing jobs:" << endl;
        description = "";
        cin.ignore();
        getline(cin, description);

        if(description.size() && description.compare("tick") && description.compare("continue") && description.compare("exit")) {

            cout << "Enter the number of ticks it takes to complete the job: ";
            cin >> ticks;
            if(cin.fail()){ invalid(); return 0; }
            if(!minMet(ticks, "ticks"))
                continue;

            cout << "Enter the number of Processors required for the job: ";
            cin >> processes;
            if(cin.fail()){ invalid(); return 0; }
            if(!minMet(processes, "processors"))
                continue;

            Job * job = new Job{ description, processes, ticks };
            project.insert(*job);
        }

        project.tick();
        cout << endl;
        project.status();
    }
    return 0;
}