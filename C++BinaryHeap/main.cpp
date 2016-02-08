#include "binaryHeap.cpp"
using namespace std;

int main() {

    binaryHeap<int> *heap = new binaryHeap<int>;

    heap->push(2);
    heap->push(5);
    heap->push(3);
    heap->push(25);
    heap->push(4);
    heap->push(17);
    heap->push(3);
    heap->push(8);
    heap->showHeap();

    heap->pop();
    heap->showHeap();
    heap->min();
    heap->showHeap();
    heap-> pop(3);
    heap->showHeap();
    heap->pop();
    heap->showHeap();
    heap-> pop(2);
    heap->showHeap();

    return 0;
}