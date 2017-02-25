//
// Created by moonmaster on 5/20/16.
//

#ifndef LISTANDTREE_LISTANDTREE_H
#define LISTANDTREE_LISTANDTREE_H

#include "AVLTree.h"

template <class Object>
class ListAndTree : public AVLTree<Object> {

private:
    AVLTree<Object> order;
    int size = 0;

public:
    Object findKth(Object k);
    void insertAndTrack (Object i);
};

#endif //LISTANDTREE_LISTANDTREE_H
