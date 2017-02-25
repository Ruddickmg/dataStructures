//
// Created by moonmaster on 5/17/16.
//

#include "ComputeBstInfo.h"
#include "Node.h"

template <class Object>
int ComputeBstInfo<Object>::nodes(Node<Object> * n) {
    if(n == nullptr)
        return 0;
    return nodes(n->left) + nodes(n->right) + 1;
}

template <class Object>
int ComputeBstInfo<Object>::leaves(Node<Object> * n) {

    if (n == nullptr)
        return 0;

    return n->left == nullptr && n->right == nullptr ? 1 : leaves(n->left) + leaves(n->right);
}

template <class Object>
int ComputeBstInfo<Object>::fullNodes(Node<Object> * n) {
    if(n == nullptr)
        return 0;
    return leaves(n->left) + leaves(n->right) + (n->left != nullptr && n->right != nullptr ? 1 : 0);
}

template class ComputeBstInfo <int>;
