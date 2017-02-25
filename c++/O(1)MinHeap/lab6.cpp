#include <ostream>
#include <iostream>
#include "lab6.h"

template <class Object>
void lab6<Object>::push(Object value) {

    Node * node = new Node;
    node->value = value;

    if (isEmpty())

        head = tail = min = node;

    else {

        node->tail = head;
        head = head->head = node;

        if(node->value < min->value) {

            node->min = min;
            min = node;
        }
    }
}

template <class Object>
bool lab6<Object>::isEmpty() { 

    return head == nullptr; 
}

template <class Object>
Object lab6<Object>::pop() {

    if (!isEmpty()) {

        if (head == min)

            min = head->min;

        Object tmp = head->value;

        if (head->tail) 

            head = head->tail;

        head->head = nullptr;

        return tmp;
    }
}

template <class Object>
Object lab6<Object>::top() { 

    if(!isEmpty()) 

        return head->value; 
}

template <class Object>
Object lab6<Object>::getMin() { 

    if(!isEmpty()) 

        return min->value; 
}

template <class Object>
void lab6<Object>::print() {

    std::cout << "[";

    if (!isEmpty()) {

        Node * node = head;

        std::cout << node->value;

        while (node->tail != nullptr) {

            node = node->tail;
            std::cout << ", " << node->value;
        }

    } else std::cout << " empty ";

    std::cout << "]" << std::endl;
}

template class lab6<int>;