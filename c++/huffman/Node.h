//
// Created by moonmaster on 5/31/16.
//

#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H
#include <iostream>

template <class Object>
class Node {

public:
    Node (Object v = 0, int p = 0) : probability{ p }, value { v }{};
    Object value;

    int probability = 0;
    int side = 0;
    bool parent = 0;

    Node * left = nullptr;
    Node * right = nullptr;

    bool operator< (Node rhs) { return probability < rhs.probability; }
    bool operator> (Node rhs) { return probability > rhs.probability; }
    bool operator<= (Node rhs) { return probability <= rhs.probability; }
    bool operator>= (Node rhs) { return probability >= rhs.probability; }
    bool operator== (Node rhs) { return probability == rhs.probability; }
    bool operator!= (Node rhs) { return probability != rhs.probability; }

    bool operator< (Node * rhs) { return probability < rhs->probability; }
    bool operator> (Node * rhs) { return probability > rhs->probability; }
    bool operator<= (Node * rhs) { return probability <= rhs->probability; }
    bool operator>= (Node * rhs) { return probability >= rhs->probability; }
    bool operator== (Node * rhs) { return probability == rhs->probability; }
    bool operator!= (Node * rhs) { return probability != rhs->probability; }


    friend std::ostream &operator<< (std::ostream & out, const Node & node)
    {
        out << "{ ";
        if (node.value != '\0')
            out << "Value: " << node.value;
        else out << "Decision node";
        return out << ", Probability: " << node.probability << " }";
    }
};


#endif //HUFFMAN_NODE_H
