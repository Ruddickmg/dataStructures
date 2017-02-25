//
// Created by moonmaster on 2/9/16.
//

#ifndef HASH_HASHTABLE_H
#define HASH_HASHTABLE_H

#include <ostream>
#include <string>
#include <list>
#include <vector>
#include <iostream>

template <class HO>
class HashTable
{
public:
    explicit HashTable( long size = 101 ) : currentSize{ 0 }{ theLists.resize(101); };
    bool contains( const HO & x );
    bool insert(const HO & x );
    bool remove(const HO & x );

private:
    std::vector<std::list<HO>> theLists;   // The array of Lists
    void makeEmpty();
    int currentSize;
    void rehash( );
    int hash( const std::string & hashString ) const;
    int myhash( const HO & employee ) const;
    typename std::list<HO>::iterator find(typename std::list<HO>::iterator start, typename std::list<HO>::iterator end, const HO x ) const;
};
#endif //HASH_HASHTABLE_H
