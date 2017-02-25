//
// Created by moonmaster on 5/17/16.
//

#ifndef WK3_CH4_COMPUTEBSTINFO_H
#define WK3_CH4_COMPUTEBSTINFO_H
#include "Node.h"

template <class Object>
class ComputeBstInfo {

public:
    int nodes (Node<Object> * n);
    int leaves (Node<Object> * n);
    int fullNodes (Node<Object> * n);
};


#endif //LAB3_CHAP4_BSTCOMPUTATE_H


