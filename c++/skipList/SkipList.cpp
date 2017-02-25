#include "SkipList.h"

// has trouble with the end of the list

template <class Object>
SLNode<Object> * SkipList<Object>::locate(Object input, int key, bool search) {

    location = beginning;
    int i = location->index();

    while (key > location->key()) {

        if((location = location->level((i = update(i, key)))) == nullptr)
            break;

        if(location->key() == key)
            if (search) return location;
            else key += 1;
    }
    return new SLNode<Object> { input, levels, key };
}

template <class Object>
int SkipList<Object>::insert(Object input) {

    SLNode<Object> * node = locate(input, generateKey());
    int level = 0;

    for(int i = node->index(); i >= 0; i -= 1)
        updates[i]->connect(node, limit(i));

    while (location != nullptr && node->level() > level) {

        if(location->level() > level)
            node->connect(location, level);

        level = location->level();
        location = location->top();
    }
    //printUpdates(node);
    length += 1;
    return node->key();
}

template <class Object>
Object SkipList<Object>::remove(int key) {
    SLNode<Object> * node = locate(0, key, true);
    if(node->connected()) {
        length -= 1;
        return deleteNode(node);
    }
}

template <class Object>
Object SkipList<Object>::deleteNode(SLNode<Object> * node) {
    //printUpdates(node);
    //std::cout << std::endl;
    //printUpdates();
    //std::cout << " -=========================== =================== ========== !!!!!!!!!!!!!!!!!! ====== =============================== " << std::endl << std::endl;
    for (int i = node->index(); i >= 0; i -= 1) {
        updates[i]->connect(node->level(i), limit(i));
        //printUpdates(updates[i]);
    }
    Object value = node->value();
    delete node;
    return value;
}

template <class Object>
int SkipList<Object>::update(int i, int key) {
    while (i > 0 && location->level(i)->key() >= key)
        updates[i--] = location;
    updates[i] = location;
    return i;
}

template <class Object>
int SkipList<Object>::limit(int i) { return i - 1 >= 0 ? updates[i - 1]->level() : 0; };

template <class Object>
Object SkipList<Object>::find(int key) {
    SLNode<Object> * node = locate(0, key, true);
    if(node->connected())
        return node->value();
}

template <class Object>
int SkipList<Object>::size() { return length; };

template <class Object>
bool SkipList<Object>::empty() { return size() <= 0; }

template <class Object>
int SkipList<Object>::generateKey() { return (rand() % (max - 1) + 1); }

template <class Object>
void SkipList<Object>::printUpdates() {
    std::cout << std::endl << "----------------------- updates ---------------------" << std::endl << std::endl;
    for(long i = updates.size() - 1; i >= 0; i -= 1)
        std::cout << "update level:" << i << " = " << *updates[i] << std::endl;
    std::cout << std::endl << "----==============-- end updates --===============----" << std::endl;
    std::cout << std::endl;
}

template <class Object>
void SkipList<Object>::printUpdates(SLNode<Object> * node) {
    std::cout << std::endl << "---------------------- results -----------------------" << std::endl << std::endl;
    std::cout << "node: " << *node << std::endl << std::endl;
    for(long i = node->index(); i >= 0; i -= 1)
        std::cout << "node level: " << i << " = " << *node->level(i) << std::endl;
    std::cout << std::endl << "----==============-- end results --===============----" << std::endl;
    std::cout << std::endl;
}

template <class Object>
void SkipList<Object>::printAllUpdates(SLNode<Object> * all, int num) {

    if(all == nullptr) {
        std::cout << std::endl << "-------------==============-- all results --===============-------------" << std::endl << std::endl;
        all = beginning;
    }

    num += 1;

    if(all->level(0) == nullptr || *all == *end || num > 10)
        return;

    std::cout << std::endl;
    for (int i = all->index(); i >= 0; i -= 1) {

        for (int k = 1; k < num; k += 1)
            std::cout << "                   ";

        if (num > 1) std::cout << "--> ";
        std::cout << "lvl: " << i + 1 << ", frm: " << all->key() << ": " << *all->level(i) << std::endl;
        printAllUpdates(all->level(i), num);
    }
    std::cout << std::endl;
    if (num <= 1) std::cout << std::endl << "-------------==============-- end results --===============-------------" << std::endl << std::endl;
}


template class SkipList <int>;
template class SkipList <char>;