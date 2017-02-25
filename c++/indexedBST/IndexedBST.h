//
// Created by moonmaster on 5/21/16.
//

#ifndef BINARYHEAP_INDEXEDBST_H
#define BINARYHEAP_INDEXEDBST_H


#include "BinarySearchTree.h"
template <class Object>
class IndexedBST : public BinarySearchTree<Object> {

private:
    void del(Node<Object> * & node);
    void insert(Node<Object> * node, Node<Object> * parent);

public:
    void del(Object val);
    void insert(Object i);
    Object findKth(int k, bool decrease = false);
};


#endif //BINARYHEAP_INDEXEDBST_H
