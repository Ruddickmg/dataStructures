#include <algorithm>
#include "Node.h"
#include "AVLTree.h"
#include <iostream>

template <class Object>
void AVLTree<Object>::insert(Object i) {
    Node<Object> * node = new Node<Object>{ i };
    if(this->empty()) this->root = node;
    else recursiveInsert(node, this->root);
}

template <class Object>
void AVLTree<Object>::insert(Node<Object> * node) {
    if(this->empty()) this->root = node;
    else recursiveInsert(node, this->root);
}

template <class Object>
void AVLTree<Object>::del(Object val) { del(val, this->root); }

template <class Object>
Node<Object> * AVLTree<Object>::del( const Object & val, Node<Object> * node)
{
    if( node != nullptr ) {
        if (val < node->value)
            del(val, node->left);
        else if (val > node->value)
            del(val, node->right);
        else if (node->left != nullptr && node->right != nullptr) {
            node->value = this->findMin(node->right);
            del(node->value, node->right);
        } else {
            Node<Object> *oldNode = node;
            node = (node->left != nullptr) ? node->left : node->right;
            delete oldNode;
        }
        balance(node);
    }
}

template <class Object>
void AVLTree<Object>::recursiveInsert( Node<Object> * & node, Node<Object> * & parent )
{
    if(parent == nullptr)
        parent = node;
    else {
        node->parent = parent;
        if (node->value < parent->value)
            recursiveInsert(node, parent->left);
        else if (node->value > parent->value)
            recursiveInsert(node, parent->right);
    }
    balance( parent );
}

// Assume t is balanced or within one of being balanced
template <class Object>
void AVLTree<Object>::balance( Node<Object> * & node )
{
    if(nodeHeight( node->left ) - nodeHeight( node->right ) > ALLOWED_IMBALANCE )

    if( nodeHeight( node->left->left ) >= nodeHeight( node->left->right ) )
        rotateWithLeftChild( node );
    else doubleWithLeftChild( node );

    else if( nodeHeight( node->right ) - nodeHeight( node->left ) > ALLOWED_IMBALANCE )

    if( nodeHeight( node->right->right ) >= nodeHeight( node->right->left ) )
        rotateWithRightChild( node );
    else doubleWithRightChild( node );

    node->height = std::max( nodeHeight( node->left ), nodeHeight( node->right ) ) + 1;
}

template <class Object>
void AVLTree<Object>::rotateWithLeftChild( Node<Object> * & k2 )
{
    Node<Object> *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = std::max( nodeHeight( k2->left ), nodeHeight( k2->right ) ) + 1;
    k1->height = std::max( nodeHeight( k1->left ), k2->height ) + 1;
    k2 = k1;
}

template <class Object>
void AVLTree<Object>::rotateWithRightChild( Node<Object> * & k2 )
{
    Node<Object> *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = std::max( nodeHeight ( k2->right ), nodeHeight ( k2->left ) ) + 1;
    k1->height = std::max( nodeHeight ( k1->right ), k2->height ) + 1;
    k2 = k1;
}

template <class Object>
int AVLTree<Object>::nodeHeight( Node<Object> * t ) const
{
    return t == nullptr ? -1 : t->height;
}

template <class Object>
void AVLTree<Object>::doubleWithLeftChild( Node<Object> * & k3 )
{
    rotateWithRightChild( k3->left );
    rotateWithLeftChild( k3 );
}

template <class Object>
void AVLTree<Object>::doubleWithRightChild( Node<Object> * & k3 )
{
    rotateWithLeftChild( k3->right );
    rotateWithRightChild( k3 );
}

template class AVLTree<int>;
