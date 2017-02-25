#include <iostream>
#include "ListAndTree.h"

using namespace std;

int main() {

    ListAndTree<int> l;

    l.insertAndTrack(1); // 0
    l.insertAndTrack(5); // 1
    l.insertAndTrack(3); // 2
    l.insertAndTrack(8); // 3
    l.insertAndTrack(10); // 4
    l.insertAndTrack(15); // 5
    l.insertAndTrack(2); // 6
    l.insertAndTrack(4); // 7
    l.insertAndTrack(90); // 8
    l.insertAndTrack(37); // 9
    l.insertAndTrack(50); // 10

    cout << endl;
    l.inOrder().print();

    cout << endl;
    cout << "position #9: " << l.findKth(9) << endl;
    cout << "position #3: " << l.findKth(3) << endl;

    return 0;
};