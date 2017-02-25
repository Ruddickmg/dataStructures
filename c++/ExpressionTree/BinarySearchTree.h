//
// Created by moonmaster on 5/13/16.
//

#ifndef SIMPLEBST_BINARYSEARCHTREE_H
#define SIMPLEBST_BINARYSEARCHTREE_H

#include <vector>
#include "List.h"
#include "Node.h"

template <class Object>
class BinarySearchTree {

protected:
    Node<Object> * nextRight (Node<Object> * p);
    Node<Object> * position = nullptr;
    Node<Object> * root = nullptr;
    Node<Object> * right();
    Node<Object> * left();

private:
    void insert (Node<Object> * node, Node<Object> * parent);
    Node<Object> * del(Object val, Node<Object> * ptr);
    int height (Node<Object> * node);

public:
    void insert (Object i);
    void del (Object val);
    Object findMin();
    Object findMax();
    bool empty ();
    bool member (Object i);
    Node<Object> * itr ();
    Node<Object> * top ();
    int height ();
};

#endif //SIMPLEBST_BINARYSEARCHTREE_H
