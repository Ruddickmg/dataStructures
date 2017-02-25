//
// Created by moonmaster on 5/23/16.
//

#include "LCS.h"
#include <iostream>

void LCS::init (std::vector<std::vector<int> > & array, long m, long n) {

    array.resize(m);

    for (int i = 0; i < m; i += 1)

        array[i].resize(n);
}

int LCS::upLeft (std::vector<std::vector<int> > array, int i, int j) { 

    return array[(i - 1)][(j - 1)]; 
}

int LCS::left (std::vector<std::vector<int> > array, int i, int j) { 

    return array[(i - 1)][j]; 
}

int LCS::up (std::vector<std::vector<int> > array, int i, int j) { 

    return array[i][(j - 1)]; 
}

int LCS::length(std::string X, std::string Y) {

    long m = X.size();
    long n = Y.size();

    init(c, m, n);

    for (int i = 1; i < m; i += 1)

        c[i][0] = 0;

    for (int j = 0; j < n; j += 1)

        c[0][j] = 0;

    for (int i = 1; i < m; i += 1)

        for (int j = 1; j < n; j += 1)

            c[i][j] = (X[i] == Y[j]) ? 1 + upLeft(c, i, j) : std::max(left(c, i, j), up(c, i, j));

    return c[m - 1][n - 1];
}

std::string LCS::print(std::string X, std::string Y) {

    length(X, Y);

    std::string tmp = "";

    long i = c.size() - 1, j = c[0].size() - 1;

    while (i != 0 && j != 0)

        if (X[i] == Y[j]) {

            tmp.insert(0, 1, X[i]);
            j -= 1;
            i -= 1;

        } else if (left(c, i, j) < up(c, i, j))

            j -= 1;

        else i -= 1;
        
    return tmp;
}
