//
// Created by moonmaster on 5/31/16.
//

#ifndef HUFFMAN_HUFFMANTREE_H
#define HUFFMAN_HUFFMANTREE_H
#include "BinaryHeap.h"
#include "Node.h"

template <class Object>
class HuffmanTree {
    BinaryHeap<Node<Object>*> cue;
    Node<Object> * root = nullptr;

public:
    void insert(Object value, int probability);
    void build();
    Object find(int key);
    //friend std::ostream &operator<< (std::ostream & out, HuffmanTree & tree) { return out << "[" << tree.print(out, tree.root) << "]"; }
    void print(Node<Object>* node = nullptr, int i = 1);
};


#endif //HUFFMAN_HUFFMANTREE_H
