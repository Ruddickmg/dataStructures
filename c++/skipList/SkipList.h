//
// Created by moonmaster on 5/23/16.
//

#ifndef SKIPLIST_SKIPLIST_H
#define SKIPLIST_SKIPLIST_H

#include "SLNode.h"

template <class Object>
class SkipList {

private:
    int max;
    int levels;
    int length = 0;
    int generateKey();
    int limit(int i);
    int update(int i, int key);
    std::vector<SLNode<Object>*> updates;
    SLNode<Object> * beginning;
    SLNode<Object> * location;
    SLNode<Object> * end;
    Object deleteNode(SLNode<Object> *node);

public:

    SkipList (int l, int m, int low) : max{ m }, levels{ l }, end{ new SLNode<Object>{ 0, levels, m, true }}
    {
        srand(time(0));
        end->clear(levels);
        beginning = new SLNode<Object>{ 0, levels, low, true };
        beginning->clear(levels);
        beginning->connect(end);
        updates.resize(levels);
    }

    bool empty();
    int size();
    int insert (Object input);
    Object remove (int key);
    Object find (int key);
    SLNode<Object> * locate (Object input, int key, bool search = false);

    friend std::ostream& operator <<(std::ostream& out, SkipList<Object>& list) {

        SLNode<Object> * node = list.beginning->bottom();

        out << "[";

        if(node != nullptr && node != list.end)
            out << std::endl << "   " << *node;
        else out << " Empty ";

        node = node->bottom();

        while(node != nullptr && node != list.end){
            out << ", " << std::endl << "   " << *node;
            node = node->bottom();
        }

        if (node != nullptr)
            out << std::endl;

        out << "]";

        return out;
    }

    void printUpdates();
    void printUpdates(SLNode<Object> *node);
    void printAllUpdates(SLNode<Object> * node = nullptr, int num = 0);
};

#endif //SKIPLIST_SKIPLIST_H
