#include <iostream>
#include "BinarySearchTree.h"
#include "ComputeBstInfo.h"
#include "ExpressionTree.h"

using namespace std;
int main() {

    ComputeBstInfo<int> compute;
    ExpressionTree<int> et;

    et.insert('+');
    et.insert('/');
    et.insert(9);
    et.insert(3);
    et.insert('*');
    et.insert('-');
    et.insert(4);
    et.insert(6);
    et.insert(2);

    cout << endl;

    et.print();
    cout << endl;

    cout << "Evaluated expression tree: " << et.evaluate() << endl;
    cout << "Nodes: " << compute.nodes(et.top()) << endl;
    cout << "Leaves: " << compute.leaves(et.top()) << endl;
    cout << "Full Nodes: " << compute.fullNodes(et.top()) << endl;

    return 0;
}