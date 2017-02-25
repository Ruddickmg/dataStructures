//
// Created by moonmaster on 5/17/16.
//

#ifndef LAB3_CHAP4_NODE_H
#define LAB3_CHAP4_NODE_H

#include <stddef.h>

template <class Object>
class Node {
public:
    Object value;
    char operate;
    bool isOperator = false;
    Node * left = nullptr;
    Node * right = nullptr;
    Node * parent = nullptr;
};

#endif //LAB3_CHAP4_NODE_H
