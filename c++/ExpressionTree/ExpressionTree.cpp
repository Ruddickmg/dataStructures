//
// Created by moonmaster on 5/18/16.
//

#include <iostream>
#include "ExpressionTree.h"

template <class Object>
const bool ExpressionTree<Object>::isOperator(const char & input) const {
    return operators.find(input) != std::string::npos;
}

template <class Object>
bool ExpressionTree<Object>::isFull(Node<Object> * node) { return node->left != nullptr && node->right != nullptr; }

template <class Object>
bool ExpressionTree<Object>::isLeaf(Node<Object> * node) { return node->left == nullptr && node->right == nullptr; }

template <class Object>
void ExpressionTree<Object>::insert(Object input) {

    Node<Object> * leaf = new Node<Object>;
    leaf->value = input;

    if (this->root == nullptr)
        throw "first element must be an operator";
    else insert(leaf, this->root);
}

template <class Object>
void ExpressionTree<Object>::insert(char input) {

    Node<Object> * leaf = new Node<Object>;
    leaf->operate = input;

    if(isOperator(input))
        leaf->isOperator = true;
    else throw "invalid operator: " + input;

    if (this->root == nullptr && leaf->isOperator)
        this->root = leaf;
    else insert(leaf, this->root);
}

template <class Object>
void ExpressionTree<Object>::insert(Node<Object> * leaf, Node<Object> * node) {

    leaf->parent = node;

    if (node->left == nullptr)
        node->left = leaf;

    else if (node->left->isOperator)
        insert(leaf, node->left);

    else if (node->right == nullptr)
        node->right = leaf;

    else if (node->right->isOperator)
        insert(leaf, node->right);

    else {
        Node<Object> * right = nextOpenRight(node);
        if(right != nullptr)
            if(right == this->right())
                this->position = right->right = leaf;
            else insert(leaf, right);
    }
}

template <class Object>
void ExpressionTree<Object>::print () {

    Node<Object> * end = this->right();
    Node<Object> * node = this->root;

    std::cout << "[";
    while (node != end){

        printNode(node);
        std::cout << ", ";
        this->position = node;
        if(node->left != nullptr)
            node = node->left;
        else node = this->nextRight(node);

    }

    printNode(end);
    std::cout << "]" << std::endl;
}

template <class Object>
void ExpressionTree<Object>::printNode (Node<Object> * node){
    if (node->isOperator)
        std::cout << node->operate;
    else std::cout << node->value;
}

template <class Object>
Node<Object> * ExpressionTree<Object>::nextOpenRight(Node<Object> * p) {
    if(p == nullptr) throw "p is null";
    if(p->right == nullptr || p->right->isOperator)
        return p->right == nullptr ? p : p->right;
    else return p->parent != nullptr ? nextOpenRight(p->parent) : nullptr;
}

template <class Object>
int ExpressionTree<Object>::eval(Node<Object> * node) {
    if(node == nullptr) throw "node is null";
    Node<Object> *left = node->left, *right = node->right;
    return expression(node->operate, left->isOperator ? eval(left) : left->value, right->isOperator ? eval(right) : right->value);
}

template <class Object>
int ExpressionTree<Object>::expression (char operation, Object val1, Object val2) {
    switch (operation) {
        case '+': return val1 + val2;
        case '/': return val1 / val2;
        case '-': return val1 - val2;
        case '*': return val1 * val2;
        default: throw "Invalid operator";
    }
}

template <class Object>
int ExpressionTree<Object>::evaluate(){ return isFull(this->root) ? eval(this->root) : throw "Incomplete Expression Tree"; }

template class ExpressionTree<int>;