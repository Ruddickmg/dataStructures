#include <iostream>
#include "ListAndTree.h"
#include "Node.h"

template <class Object>
void ListAndTree<Object>::insertAndTrack(Object i) {

    Node<Object> * node = new Node<Object>{ i };
    Node<Object> * ord = new Node<Object>{ i, node };

    if(this->empty()) this->root = node;
    else this->insert(node);

    ord->node = node;
    ord->value = size++;
    order.insert(ord);
}

template <class Object>
Object ListAndTree<Object>::findKth(Object k) {
    Node<Object> *node = order.top();
    while (node != nullptr)
        if (k < node->value)
            node = node->left;
        else if (k > node->value)
            node = node->right;
        else return node->node->value;
}

template class ListAndTree<int>;
