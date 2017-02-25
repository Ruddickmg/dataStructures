#include <iostream>
#include <vector>
#include "merge.h"

int main() {

    merge<std::vector<int>> m;

    std::vector<int> a = {39, 19, 80, 12, 201, 66, 79, 20, 25, 29, 59, 39, 59, 399, 546, 23, 1, 234, 5667, 43, 5, 7, 2, 6, 44, 995, 343, 2543, 44, 222, 266, 34, 1124, 90, 23, 52, 66, 74, 134, 5675675, 66786, 44, 98, 46, 5 };

    a = m.sort(a);

    m.print();

    return 0;
}