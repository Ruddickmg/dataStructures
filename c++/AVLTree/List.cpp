#include "List.h"
#include <iostream>

template <class Object>
void List<Object>::insert (Object i) {

    ListNode * n = new ListNode;
    n->value = i;

    ListNode * node = head;

    if (empty()) {
        head = n;
        head->head = nullptr;
    } else {
        while (node->tail != nullptr)
            node = node->tail;

        tail = node->tail = n;
        tail->head = node;
    }
    length += 1;
}

template <class Object>
void List<Object>::print () {
    ListNode * node = head;
    if(empty()) {
        std::cout << "Empty list" << std::endl;
    } else {
        std::cout << "[";
        while (node->tail != nullptr) {
            std::cout << node->value << ", ";
            node = node->tail;
        }
    }
    std::cout << node->value << "]" << std::endl;
};

template <class Object>
typename List<Object>::ListNode * List<Object>::pop () {
    ListNode * h = tail;
    tail->head->tail = nullptr;
    tail = tail->head;
    length -= 1;
    return h;
};

template <class Object>
bool List<Object>::empty () { return head == nullptr; }

template <class Object>
int List<Object>::size () { return length; }

template class List<int>;
