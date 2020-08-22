//
// Created by Lin Zhihao
/*
 * This file implements a map template.
 * Base: red black tree.
 * Data will be stored in a red black tree, sorted by the unique key.
 * Supported:
 *  1. [] operator to directly access data
 *  2. Insert/erase elements from the map
 */

#ifndef MY_STL_MAP_H
#define MY_STL_MAP_H
#include <iostream>
#include "red_black_tree.hpp"
#include "pair.h"

template<typename Type_key, typename Type_data>
class map{
private:
    Red_Black_Tree<pair<Type_key, Type_data>> rbt_base;
    void print() const;
public:
    //Default constructor
    map() = default;

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
    bool erase(Type_key key);

    //Clear all the elements in the map
    void clear();

    //Return a pointer to the key related data
    //If the key doesn't exist, return NULL
    Type_data* find(const Type_key& key) const;
};

#endif //MY_STL_MAP_H
