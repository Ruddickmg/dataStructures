//
// Created by moonmaster on 5/21/16.
//

#ifndef BINARYHEAP_BINARYSEARCHTREE_H
#define BINARYHEAP_BINARYSEARCHTREE_H


#include "Node.h"
#include "List.h"

template <class Object>
class BinarySearchTree {
protected:
    Node<Object> * root = nullptr;

private:
    Node<Object> * position = nullptr;
    Node<Object> * nextRight (Node<Object> * p);
    void insert (Node<Object> * node, Node<Object> * parent);
    Node<Object> * del(Object val, Node<Object> * ptr);
    int height (Node<Object> * node);
    List<Object> order (Node<Object> * node, List<Object> & ordered);

public:
    virtual void insert (Object i);
    virtual void del (Object val);
    Object findMin();
    Object findMax();
    bool empty ();
    bool member (Object i);
    List<Object> inOrder ();
    Node<Object> * itr ();
    Node<Object> * top();
    int height ();

};


#endif //BINARYHEAP_BINARYSEARCHTREE_H
