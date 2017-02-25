#ifndef LISTANDTREE_AVLTREE_H
#define LISTANDTREE_AVLTREE_H

#include "Node.h"
#include "BinarySearchTree.h"

template <class Object>
class AVLTree : public BinarySearchTree<Object> {

protected:
    void recursiveInsert(Node<Object> * & node, Node<Object> * & parent);

private:
    static const int ALLOWED_IMBALANCE = 1;
    Node<Object> *del(const Object &x, Node<Object> *t);
    int nodeHeight(Node<Object> *t) const;
    void doubleWithLeftChild(Node<Object> *&k3);
    void doubleWithRightChild(Node<Object> *&k3);
    void rotateWithRightChild(Node<Object> *&k2);
    void rotateWithLeftChild(Node<Object> *&k2);
    void balance(Node<Object> *&node);

public:
    void insert (Node<Object> * node);
    void insert (Object i);
    void del (Object val);
};

#endif //LISTANDTREE_AVLTREE_H
