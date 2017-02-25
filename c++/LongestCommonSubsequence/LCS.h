//
// Created by moonmaster on 5/23/16.
//

#ifndef LCS_LCS_H
#define LCS_LCS_H
#include <vector>
#include <string>

class LCS {
private:
    std::vector<std::vector<int>> c;
    void init(std::vector<std::vector<int>> &array, long m, long n);
    int upLeft(std::vector<std::vector<int>> array, int i, int j);
    int left(std::vector<std::vector<int>> array, int i, int j);
    int up(std::vector<std::vector<int>> array, int i, int j);

public:
    int length(std::string X, std::string Y);
    std::string print(std::string X, std::string Y);
};


#endif //LCS_LCS_H
