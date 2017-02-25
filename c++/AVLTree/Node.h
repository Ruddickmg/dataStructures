//
// Created by moonmaster on 5/20/16.
//

#ifndef LISTANDTREE_NODE_H
#define LISTANDTREE_NODE_H


template <class Object>
class Node {
public:
    Node (Object val, Node * n = nullptr) : value{ val }, node{ n }{};
    Object value;
    int height;
    const Node * node;
    Node * left = nullptr;
    Node * right = nullptr;
    Node * parent = nullptr;
};


#endif //LISTANDTREE_NODE_H
