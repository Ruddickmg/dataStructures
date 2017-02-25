//
// Created by moonmaster on 5/31/16.
//

#include "HuffmanTree.h"
#include <sstream>

template <class Object>
void HuffmanTree<Object>::insert(Object value, int probability) { cue.push(new Node<Object>{ value, probability }); }

template <class Object>
void HuffmanTree<Object>::build() {

    if(!cue.size()) {
        std::cout << "[empty]" << std::endl;
        return;
    }

    Node<Object> * node, * parent = new Node<Object>{};
    parent->parent = true;

    while(cue.size() > 0) {
        node = cue.pop();

        if (parent->left == nullptr) {
            parent->left = node;
            parent->probability += node->probability;

        }else if (parent->right == nullptr){
            node->side = 1;
            parent->right = node;
            parent->probability += node->probability;

            if(cue.size()) {
                cue.push(parent);
                parent = new Node<Object>{};
                parent->parent = true;
            }
        }
    }
    root = parent;
};

template <class Object>
Object HuffmanTree<Object>::find(int key){
    std::ostringstream os;
    Node<Object> * node = root;
    os << key;
    std::string binString = os.str();

    for(int i = 0; i < binString.length(); i += 1)
        if( node->left != nullptr && node->left->side + '0' == binString[i]) {
            node = node->left;
        } else if(node->right != nullptr) {
            node = node->right;
        } else return 0;
    return node->value;
};

template <class Object>
void HuffmanTree<Object>::print(Node<Object> * node, int i) {

    if(node == nullptr) {
        node = root;
        std::cout << std::endl << "root: ";
    }

    if(node->parent) {
        std::cout << *node << std::endl;
        for(int a = 0; a < i; a += 1)
            std::cout << "          ";
        std::cout << "\\" << std::endl;

        for(int a = 0; a < i; a += 1)
            std::cout << "          ";
        std::cout << " ----- left: ";
        print(node->left, i + 1);

        for(int a = 0; a < i; a += 1)
            std::cout << "           ";
        std::cout << " \\" << std::endl;

        for(int a = 0; a < i; a += 1)
            std::cout << "           ";
        std::cout << "  - right: ";
        print(node->right, i + 1);
        std::cout << std::endl;

    } else std::cout << *node << std::endl;
}

template class HuffmanTree <char>;