//
// Created by moonmaster on 5/20/16.
//

#ifndef LISTANDTREE_LIST_H
#define LISTANDTREE_LIST_H

template <class Object>
class List {

private:
    struct ListNode {
        Object value;
        ListNode * head;
        ListNode * tail;
    };
    ListNode * head = nullptr;
    ListNode * tail = nullptr;
    int length = 0;

public:
    void insert(Object i);
    void print ();
    int size ();
    bool empty ();
    ListNode * pop();
};


#endif //LISTANDTREE_LIST_H
