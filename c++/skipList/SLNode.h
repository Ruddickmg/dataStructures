//
// Created by moonmaster on 5/23/16.
//

#ifndef SKIPLIST_SLNODE_H
#define SKIPLIST_SLNODE_H

#include <list>
#include <iostream>
#include <vector>

template <class Object>
class SLNode {
private:
    int randomNumber(int max);
    const int max;
    const int ke;
    const int lvl;
    const int ind;
    const Object val;
    std::vector<SLNode<Object> *> nodes;

public:
    SLNode<Object>(Object v, int m, int k, bool beginningOrEnd = false) : lvl{ beginningOrEnd ? m: randomNumber(m) }, ke{ k }, val{ v }, max{ m }, ind { lvl - 1 } { clear(lvl); };
    SLNode<Object> *top();
    SLNode<Object> *bottom();
    SLNode<Object> *level(int i);
    void connect(SLNode<Object> *node, int limit = 0);
    void clear(int limit);
    const int & level() const;
    const int & index() const;
    const int & key() const;
    const Object & value() const;
    bool connected();

    friend std::ostream& operator <<(std::ostream & out, const SLNode & node) { return out << "{ Value: " << node.value() << ", Level: " << node.level() << ", Key: " << node.key() << " }"; }

    const bool operator>(const SLNode & rhs) { return ke > rhs.key(); }
    const bool operator<(const SLNode &rhs) { return ke < rhs.key(); }
    const bool operator>=(const SLNode &rhs) { return *this < rhs || *this == rhs; }
    const bool operator<=(const SLNode &rhs) { return *this > rhs || *this == rhs; }
    const bool operator==(const SLNode &rhs) { return this->key() == rhs.key(); }
    const bool operator!=(const SLNode &rhs) { return !(*this == rhs); }
};


#endif //SKIPLIST_SLNODE_H
