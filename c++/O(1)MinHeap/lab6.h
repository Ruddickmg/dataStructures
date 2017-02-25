#ifndef LAB6_LAB6_H
#define LAB6_LAB6_H

template <class Object>

class lab6 {

private:

    struct Node {
        Object value;
        Node * head = nullptr;
        Node * tail = nullptr;
        Node * min = nullptr;
    };
    Node * min = nullptr;
    Node * head = nullptr;
    Node * tail = nullptr;

public:

    void push(Object value);
    bool isEmpty();
    Object pop();
    Object top();
    Object getMin();
    void print();

};

#endif //LAB6_LAB6_H
