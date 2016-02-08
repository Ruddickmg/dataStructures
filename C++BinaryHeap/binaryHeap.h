//
// Created by moonmaster on 2/7/16.
//

#ifndef BINARYHEAP_BINARYHEAP_H
#define BINARYHEAP_BINARYHEAP_H

#include <vector>
#include <string>
template <class heapElement>

class binaryHeap {
    public:

        explicit binaryHeap<heapElement> (std::string prop = NULL) : property{ prop } {};
        int push (const heapElement & value);
        int size ();
        heapElement min ();
        heapElement pop (int index = 0);
        void showHeap();

    private:
        std::string property;
        std::vector<heapElement> heap;
        int swap (int index, int parentIndex);
        int value (int index);
        int parent (int index);
        int left (int i);
        int right (int i);
        bool lt(int l, int r);
        int bubble (int index);
        heapElement sortHeap(int index);
};


#endif //BINARYHEAP_BINARYHEAP_H
