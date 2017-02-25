//
// Created by moonmaster on 5/20/16.
//

#ifndef LISTANDTREE_BINARYSEARCHTREE_H
#define LISTANDTREE_BINARYSEARCHTREE_H


#include "Node.h"
#include "List.h"

template <class Object>
class BinarySearchTree {

protected:
    Node<Object> * root = nullptr;

private:
    Node<Object> * position = nullptr;
    Node<Object> * nextRight (Node<Object> * p);
    void recursiveInsert (Node<Object> * node, Node<Object> * parent);
    Node<Object> * del(Object val, Node<Object> * ptr);
    int height (Node<Object> * node);
    List<Object> order (Node<Object> * node, List<Object> & ordered);

public:
    void insert (Node<Object> * node);
    void insert (Object i);

    void del (Object val);
    Object findMin(Node<Object> * node = nullptr);
    Object findMax(Node<Object> * node = nullptr);
    bool empty ();
    bool member (Object i);
    List<Object> inOrder ();
    Node<Object> * itr ();
    Node<Object> * top();
    int height ();
};


#endif //LISTANDTREE_BINARYSEARCHTREE_H
