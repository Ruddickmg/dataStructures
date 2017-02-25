//
// Created by moonmaster on 5/31/16.
//

#ifndef HUFFMAN_BINARYHEAP_H
#define HUFFMAN_BINARYHEAP_H


#include <vector>
#include <string>
#include "Node.h"

template <class Object>
class BinaryHeap {
public:
    BinaryHeap (bool min = true) : minHeap{ min }{};
    int push (const Object & value);
    int size ();
    void showHeap();
    const Object & min () const;
    Object & pop (int index = 0);

private:
    bool minHeap;
    std::vector<Object> heap;
    int swap (int index, int parentIndex);
    int parent (int index);
    int left (int i);
    int right (int i);
    bool less (int l, int r);
    int bubble (int index);
    Object & value (int index);
    Object & sortHeap(int index);
};


#endif //HUFFMAN_BINARYHEAP_H
