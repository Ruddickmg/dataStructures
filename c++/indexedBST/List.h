#ifndef BINARYHEAP_LIST_H
#define BINARYHEAP_LIST_H

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


#endif //BINARYHEAP_LIST_H
