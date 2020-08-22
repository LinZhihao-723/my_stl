//
// Created by Lin Zhihao
/*
 * This file implements an unordered map template.
 * Base: hash table.
 * Data will be stored in a hash table, sorted by the unique key.
 * Supported:
 *  1. [] operator to directly access data
 *  2. Insert/erase elements from the map
 *  Note:
 *  The key type must have its "==" operator defined.
 */

#ifndef MY_STL_UNORDERED_MAP_H
#define MY_STL_UNORDERED_MAP_H
#include "hash_table.hpp"

template<typename Type_key, typename Type_data>
class unordered_map{
private:
    hash_table<Type_key, Type_data> _hash_table;
public:
    //Default constructor
    unordered_map() = default;

    //[] operators to access data
    //Return the reference of the key related data
    Type_data& operator[](const Type_key& key) const;

    //Return true if the map is empty
    bool empty() const;

    //Return the size of the map
    unsigned int size() const;

    //Return true if inserted successfully
    bool insert(Type_key key, Type_data data);

    //Return true if removed successfully
    bool erase(const Type_key& key);

    //Clear all the elements in the map
    void clear();

    //Return a pointer to the key related data
    //If the key doesn't exist, return NULL
    Type_data* find(const Type_key& key) const;
};

#endif //MY_STL_UNORDERED_MAP_H
