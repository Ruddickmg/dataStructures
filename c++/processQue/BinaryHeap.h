//
// Created by moonmaster on 5/21/16.
//

#ifndef PROJECT1_BINARYHEAP_H
#define PROJECT1_BINARYHEAP_H


#include <vector>
#include <string>

template <class Object>
class BinaryHeap {
public:
    BinaryHeap (bool min = true) : minHeap{ min }{};
    int push (const Object & value);
    int size ();
    Object min ();
    Object pop (int index = 0);
    void showHeap();

private:
    bool minHeap;
    std::vector<Object> heap;
    int swap (int index, int parentIndex);
    int parent (int index);
    int left (int i);
    int right (int i);
    bool less (int l, int r);
    int bubble (int index);
    Object value (int index);
    Object sortHeap(int index);
};


#endif //PROJECT1_BINARYHEAP_H
