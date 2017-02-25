#include <iostream>
#include "HuffmanTree.h"

using namespace std;

int main() {

    HuffmanTree<char> ht;

    ht.insert('1', 10);
    ht.insert('2', 12);
    ht.insert('3', 14);
    ht.insert('4', 7);
    ht.insert('5', 15);
    ht.insert('6', 17);
    ht.insert('7', 19);
    ht.insert('0', 6);

    ht.build();

    std::cout << std::endl << "printed huffman tree: " << std::endl;

    ht.print();

    std::cout << "value at binary string key 101: " << ht.find(101) << std::endl;
    std::cout << "value at binary string key 100: " << ht.find(100) << std::endl;

    return 0;
}