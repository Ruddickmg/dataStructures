//
// Created by moonmaster on 2/7/16.
//

#include "binaryHeap.h"
#include <algorithm>
#include <iostream>

// swaps the parent index with the child, returns child's new index (parent index)
// subtract one from each input to compensate for the array starting at 0 rather then 1template <class heapElement>
template <class heapElement>
int binaryHeap<heapElement>::swap(int index, int parentIndex)
{ std::swap(heap[index - 1], heap[parentIndex - 1]); return parentIndex; };

// get the value at the input index, compensate for whether there is a property being accessed or not
template <class heapElement>
int binaryHeap<heapElement>::value (int index)
{ return heap[index - 1]; };

// calculate the parent index
template <class heapElement>
int binaryHeap<heapElement>::parent (int index)
{ return index/2; };

// calculate the indexes of the left and right
template <class heapElement>
int binaryHeap<heapElement>::left (int i)
{ return i * 2; };

template <class heapElement>
int binaryHeap<heapElement>::right (int i)
{ return left(i) + 1; };

// compare the values at the two supplied indexes, return the result of whether input l is greater then input r
template <class heapElement>
bool binaryHeap<heapElement>::lt (int l, int r)
{ return value(l) < value(r); };

// if we are at the start of the array or the current nodes value is greater then its parent then return the current
// index (compensate for 0), otherwise swap the parent and child then repeat from the childs new position
template <class heapElement>
int binaryHeap<heapElement>::bubble (int index)
{ return index < 2 || lt(parent(index), index) ? index : bubble(swap(index, parent(index))); };

// add object to the heap, returns its index in the heap (-1 compensates for index actually starting @ 0)
template <class heapElement>
int binaryHeap<heapElement>::push (const heapElement & value)
{ heap.push_back(value); return bubble(size()) - 1; };

// remove and return the top item from the heap
template <class heapElement>
heapElement binaryHeap<heapElement>::pop (int index) { sortHeap(index + 1); };

// return the first value of the heap (lowest)
template <class heapElement>
heapElement binaryHeap<heapElement>::min ()
{ return heap[0]; };

// return the amount of elements in the heap (array)
template <class heapElement>
int binaryHeap<heapElement>::size ()
{ return (int) heap.size(); };

template <class heapElement>
heapElement binaryHeap<heapElement>::sortHeap(int index) {
    int l = left(index);
    int r = right(index);
    int length = size();

    // if there are no more childnodes, swap the value at the current index with the value at
    // end of the array, sort the value at the current index then remove and return the
    // last array element (the minimum element)
    if (length <= l) {
        heapElement value = heap[swap(index, length) - 1];
        bubble(index);
        heap.pop_back();
        return value;
    }

    // if the right node is in range and less then the left node then swap
    // the child with the right node, otherwise swap with the left
    sortHeap(swap(index, length > r && lt(r,l) ? r : l ));
}

template <class heapElement>
void binaryHeap<heapElement>::showHeap() {
    int s = size();
    if (property != "NULL") std::cout << property << ": ";
    std::cout << "[";
    for ( int i = 0; i < s; i+=1) {
        std::cout << heap[i];
        if(i < size() - 1) std::cout << ", ";
    }
   std::cout << "]" << std::endl;
};
