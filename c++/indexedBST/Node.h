#ifndef BINARYHEAP_NODE_H
#define BINARYHEAP_NODE_H


template <class Object>
class Node {
public:
    Object value;
    int leftSize = 0;
    Node * left = nullptr;
    Node * right = nullptr;
    Node * parent = nullptr;
};


#endif //BINARYHEAP_NODE_H
