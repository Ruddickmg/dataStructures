//
// Created by moonmaster on 5/23/16.
//

#include "SLNode.h"
template <class Object>
class SLNode;

template <class Object>
class SkipList;

template <class Object>
void SLNode<Object>::connect(SLNode<Object> * node, int limit) {
    int i = std::min(node->index(), this->index());
    while (i >= limit) nodes[i--] = node;
}

template <class Object>
void SLNode<Object>::clear(int limit) {
    nodes.resize(limit);
    for (int i = 0; i < limit; i += 1)
        nodes[i] = nullptr;
}

template <class Object>
int SLNode<Object>::randomNumber(int max) { return rand() % max + 1; }

template <class Object>
const int & SLNode<Object>::level() const { return lvl; }

template <class Object>
SLNode<Object> * SLNode<Object>::level (int i) { return nodes[i]; }

template <class Object>
SLNode<Object> * SLNode<Object>::top () { return nodes[ind]; }

template <class Object>
SLNode<Object> * SLNode<Object>::bottom () { return nodes[0]; }

template <class Object>
bool SLNode<Object>::connected(){ return nodes[0] != nullptr; }

template <class Object>
const int &SLNode<Object>::key() const { return ke; }

template <class Object>
const Object &SLNode<Object>::value() const { return val; }

template <class Object>
const int &SLNode<Object>::index() const { return ind; }


template class SLNode <char>;
template class SLNode <int>;
