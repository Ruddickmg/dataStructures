#include "BinarySearchTree.h"

template <class Object>
bool BinarySearchTree<Object>::empty() { return root == nullptr; }

template <class Object>
Node<Object> * BinarySearchTree<Object>::top() { return root; }

template <class Object>
void BinarySearchTree<Object>::insert(Object i) {
    Node<Object> * node = new Node<Object>;
    node->parent = nullptr;
    node->value = i;
    if(empty()) root = node;
    else insert(node, root);
}

template <class Object>
void BinarySearchTree<Object>::insert(Node<Object> * node, Node<Object> * parent) {

    Object p = parent->value;
    Node<Object> * l = parent->left;
    Node<Object> * r = parent->right;
    Object n = node->value;
    node->parent = parent;

    if(n < p)
    if(l != nullptr)
        return insert(node, l);
    else parent->left = node;

    else if (n > p)
    if (r != nullptr)
        return insert(node, r);
    else parent->right = node;
};

template <class Object>
bool BinarySearchTree<Object>::member(Object i){
    Node<Object> * node = root;
    while (node != nullptr)
        if(i < node->value)
            node = node->left;
        else if(i > node->value)
            node = node->right;
        else return true;
    return false;
}

template <class Object>
Node<Object> * BinarySearchTree<Object>::left() {
    Node<Object> * node = root;
    while(node->left != nullptr)
        node = node->left;
    return node;
}

template <class Object>
Node<Object> * BinarySearchTree<Object>::right() {
    Node<Object> * node = root;
    while (node->right != nullptr)
        node = node->right;
    return node;
}

template <class Object>
Object BinarySearchTree<Object>::findMin() { return left()->value; }

template <class Object>
Object BinarySearchTree<Object>::findMax() { return right()->value; }


template <class Object>
void BinarySearchTree<Object>::del(Object val) {
    del(val, root);
}

template <class Object>
Node<Object> * BinarySearchTree<Object>::del(Object val, Node<Object> * ptr) {
    if(ptr != nullptr){
        if (ptr->value == val) {
            if (ptr->left != nullptr && ptr->right != nullptr) {
                insert(ptr->right, ptr->left);
                ptr->left->parent = ptr;
                ptr = ptr->left;
            } else if (ptr->left != nullptr) {
                ptr->left->parent = ptr;
                ptr = ptr->left;
            } else {
                ptr->right->parent = ptr;
                ptr = ptr->right;
            }
        } else {
            ptr->left = del(val, ptr->left);
            ptr->right = del(val, ptr->right);
        }
    }
    return ptr;
}

template <class Object>
int BinarySearchTree<Object>::height() { return height(root); }

template <class Object>
int BinarySearchTree<Object>::height(Node<Object> * node) {

    int left = 0, right = 0;

    if(node->right != nullptr)
        left = height(node->right) + 1;

    if(node->left != nullptr)
        right = height(node->left) + 1;

    return left > right ? left : right;
};

template <class Object>
Node<Object> * BinarySearchTree<Object>::itr () {

    if(position == nullptr)
        return position = root;

    if(position->value == findMax())
        return nullptr;

    if(position->left != nullptr)
        return position = position->left;
    else
        return position = nextRight(position);
}

template <class Object>
Node<Object> * BinarySearchTree<Object>::nextRight(Node<Object> * p) {
    if(p->right != nullptr && p->right != position)
        return p->right;
    else return p->parent != nullptr ? nextRight(p->parent) : nullptr;
}

template class BinarySearchTree<int>;
