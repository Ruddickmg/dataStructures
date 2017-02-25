//
// Created by moonmaster on 2/9/16.
//

#ifndef HASH_EMPLPYEETABLE_H
#define HASH_EMPLPYEETABLE_H

#include <string>

// Example of an Employee class
class Employee
{
    public:
        explicit Employee (const std::string & n, double sa, int se) : hash{n}, name{n}, salary{sa}, seniority{se}{
            long length = hash.length();
            for(long i = 0; i < length; i += 1){
                long e = i + 2 < length ? i + 2 : i + 2 - length;
                std::swap(hash[i], hash[e]);
            }
        };
        const std::string & getName( ) const;
        const std::string hashed() const;
        bool operator==( const Employee & rhs ) const;
        bool operator!=( const Employee & rhs ) const;

        // Additional public members not shown

    private:
        std::string name;
        std::string hash;
        double salary;
        int seniority;

        // Additional private members not shown
};

#endif //HASH_EMPLPYEETABLE_H
