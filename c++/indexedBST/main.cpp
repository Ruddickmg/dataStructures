#include "BinaryHeap.h"
#include "IndexedBST.h"
#include <iostream>

using namespace std;

int main() {

    IndexedBST<int> ibst;
    BinaryHeap<int> heap;

    heap.push(2);
    heap.push(5);
    heap.push(3);
    heap.push(25);
    heap.push(4);
    heap.push(17);
    heap.push(3);
    heap.push(8);

    cout << "---------- binary heap -----------" << endl;

    heap.showHeap();

    cout << endl << "pop: " << heap.pop() << endl << endl;
    heap.showHeap();
    cout << endl << "min: " << heap.min() << endl << endl;
    heap.showHeap();
    cout << endl  << "pop: " <<  heap.pop() << endl << endl;
    heap.showHeap();
    cout << endl  << "pop: " <<  heap.pop() << endl << endl;
    heap.showHeap();
    cout << endl  << "pop: " <<  heap.pop() << endl << endl;
    heap.showHeap();
    cout<< endl << "---------- IndexedBST -----------" << endl << endl;

    ibst.insert(5);
    ibst.insert(8);
    ibst.insert(30);
    ibst.insert(3);
    ibst.insert(22);
    ibst.insert(12);
    ibst.insert(16);
    ibst.insert(80);
    ibst.insert(1123);
    ibst.insert(34);
    ibst.insert(56);
    ibst.insert(7);
    ibst.insert(32);
    ibst.insert(98);
    ibst.insert(76);
    ibst.insert(2);

    ibst.inOrder().print();
    cout << endl;

    cout << "5 kth: " << ibst.findKth(5) << endl;
    cout << "9 kth: " << ibst.findKth(9) << endl;
    cout << "11 kth: " << ibst.findKth(11) << endl;
    cout << "14 kth: " << ibst.findKth(14) << endl;

    cout << endl << "delete: 22" << endl << endl;
    ibst.del(22);

    ibst.inOrder().print();
    cout << endl;

    cout << "5 kth: " << ibst.findKth(5) << endl;
    cout << "9 kth: " << ibst.findKth(9) << endl;
    cout << "11 kth: " << ibst.findKth(11) << endl;
    cout << "14 kth: " << ibst.findKth(14) << endl;

    return 0;
}