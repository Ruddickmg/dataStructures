#include <iostream>
#include "LCS.h"

using namespace std;

int main() {

    LCS lcs;

    std::string x = "10010101";
    std::string y = "010110110";

    std::cout << "length: " << lcs.length(x, y) << std::endl;
    std::cout << "lcs: " << lcs.print(x, y) << std::endl;

    return 0;
}