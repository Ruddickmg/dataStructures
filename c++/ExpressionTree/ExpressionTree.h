//
// Created by moonmaster on 5/18/16.
//

#ifndef WK3_CH4_EXPRESSIONTREE_H
#define WK3_CH4_EXPRESSIONTREE_H

#include <string>
#include "BinarySearchTree.h"
#include "Node.h"

template <class Object>
class ExpressionTree : public BinarySearchTree<Object> {

private:
    std::string operators = "+-/*";
    Node<Object> * nextOpenRight(Node<Object> * p);
    const bool isOperator (const char & input) const;
    bool isFull (Node<Object> * node);
    bool isLeaf (Node<Object> * node);
    void insert (Node<Object> * leaf, Node<Object> * node);
    void printNode (Node<Object> * node);
    int eval (Node<Object> * node);
    int expression (char operation, Object val1, Object val2);

public:
    void insert (Object input);
    void insert (char input);
    void print ();
    int evaluate ();
};

#endif //WK3_CH4_EXPRESSIONTREE_H
