//
// Created by moonmaster on 2/9/16.
//

#include "HashTable.h"

template <class HO>
int HashTable<HO>::myhash (const HO & employee) const
{
    int key = hash(employee.hashed());
    long tableSize = theLists.capacity();
    if (tableSize == 0) return 0;

    key %= tableSize;

    if ( key < 0 ) key += tableSize;

    return key;
};

template <class HO>
void HashTable<HO>::makeEmpty( )
{
    for( int i = 0; i < theLists.size( ); i++ )
        theLists[ i ].clear( );
};

template <class HO>
typename std::list<HO>::iterator HashTable<HO>::find(
        typename std::list<HO>::iterator start,
        typename std::list<HO>::iterator end,
        const HO x) const {
    while( start != end ){
        HO employee = *start;
        if( employee.getName() == x.getName()) return start;
        start++;
    }
    return end;
};

template <class HO>
bool HashTable<HO>::contains( const HO & x )
{
    std::list<HO> & whichList = theLists[ myhash( x) ];

    return find( whichList.begin( ), whichList.end( ), x ) != whichList.end( );
};

template <class HO>
bool HashTable<HO>::remove( const HO & x )
{
    typename std::list<HO> & whichList = theLists[ myhash(x) ];
    typename std::list<HO>::iterator itr = find( whichList.begin( ), whichList.end( ), x );

    if( itr == whichList.end( ) )
        return false;

    whichList.erase( itr );
    --currentSize;
    return true;
};

template <class HO>
bool HashTable<HO>::insert( const HO & x )
{
    std::cout << "name: " << x.getName() << std::endl;
    std::cout << "hash within bounds of array size: " << myhash(x) << std::endl;
    std::list<HO> & whichList = theLists[myhash(x)];

    if (find(whichList.begin(), whichList.end(), x) != whichList.end()) return false;

    whichList.push_back(x);

    if( ++currentSize > theLists.size( )){
       // rehash( );
    }
    
    return true;
};


template <class HO>
int HashTable<HO>::hash( const std::string & hashString ) const
{
    int hashVal = hashString[0];

    for( int i = 1; i < hashString.length( ); i++ )
        hashVal = 37 * hashVal + hashString[ i ];

    return hashVal;
};

template <class HO>
void HashTable<HO>::rehash()
{
    for(int i = 0; i < theLists->size(); i += 1){ // use iterators
//        theLists[myHash(theLists[i])] = theLists[i];
    }
};
