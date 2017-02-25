#ifndef PROJECT1_JOB_H
#define PROJECT1_JOB_H

#include <string>
#include <ostream>

class Job {
public:
    Job (std::string desc, int procs, int tcks)
            : description{ desc }, process{ procs }, tic{ tcks }{};
    void setId(int id);
    void tick();
    const std::string getDescription() const;
    const int getId() const;
    const int ticks() const;
    const int processes() const;
    friend std::ostream & operator<<(std::ostream & out, const Job & j) {
        return out << "{ Id: " << j.getId() << ", Description: " << j.getDescription() << ", Processes: " << j.processes() << ", Ticks: " << j.ticks() << " }";
    }
    inline bool operator< (const Job & rhs) { return process < rhs.processes() || process <= rhs.processes() && tic < rhs.ticks(); }
    inline bool operator> (const Job & rhs) { return process > rhs.processes() || process >= rhs.processes() && tic > rhs.ticks(); }
    inline bool operator== (const Job & rhs) { return process == rhs.processes() && tic == rhs.ticks(); }
    inline bool operator!= (const Job & rhs) { return !(*this == rhs); }
    inline bool operator<= (const Job & rhs) { return !(*this > rhs); }
    inline bool operator>= (const Job & rhs) { return !(*this < rhs); }

private:
    std::string description;
    int process;
    int tic;
    int id;
};

#endif //PROJECT1_JOB_H
