//
// Created by moonmaster on 5/21/16.
//

#include "IndexedBST.h"
#include <iostream>

using namespace std;

template <class Object>

void IndexedBST<Object>::insert(Object i) {
    Node<Object> * node = new Node<Object>;
    node->parent = nullptr;
    node->value = i;
    if(this->empty()) this->root = node;
    else insert(node, this->root);
}

template <class Object>
void IndexedBST<Object>::insert(Node<Object> * node, Node<Object> * parent) {

    Object p = parent->value;
    Node<Object> * left = parent->left;
    Node<Object> * right = parent->right;
    Object value = node->value;
    node->parent = parent;

    if(value < p) {
        parent->leftSize += 1;
        if (left != nullptr)
            return insert(node, left);
        else parent->left = node;
    } else if (value > p)
        if (right != nullptr)
            return insert(node, right);
        else parent->right = node;
};

template <class Object>
Object IndexedBST<Object>::findKth(int k, bool decrease){

    Node<Object> * node = this->top();
    int size = 0;

    while (size < k && node != nullptr) {
        if (size + node->leftSize < k) {
            size += node->leftSize;
            node = node->right;
        } else {
            if (decrease)
                node->leftSize -= 1;
            node = node->left;
        }
        size += 1;
    }

    if (node != nullptr)
        return node->value;
}

template <class Object>
void IndexedBST<Object>::del(Object val) {
    int k = 0;
    Node<Object> * node = this->root;
    while (node != nullptr){
        if (node->value > val)
            node = node->left;
        else if (node->value < val) {
            k += node->leftSize;
            node = node->right;
        }else{
            findKth(k, true);
            return del(node);
        };
        k += 1;
    }
}

template <class Object>
void IndexedBST<Object>::del(Node<Object> * & node) {
    Node<Object> *&child = node->left != nullptr ? node->left : node->right;
    Node<Object> *&leaf = node->parent->left == node ? node->parent->left : node->parent->right;

    if (node->left != nullptr && node->right != nullptr)
        insert(node->right, node->left);

    leaf = child;
    delete node;
}

template class IndexedBST <int>;