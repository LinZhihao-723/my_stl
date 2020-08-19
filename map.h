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

//This structure is used to store values of map in the red black tree.
//Operators are overloaded for the red black tree operations.
template<typename Type_key, typename Type_data>
struct map_pair{
    Type_key key;
    Type_data data;
    map_pair() = default;
    map_pair(Type_key _key): key(_key) {};
    map_pair(Type_key _key, Type_data _data): key(_key), data(_data) {};
    friend bool operator<(const map_pair<Type_key, Type_data>& lhs,
                          const map_pair<Type_key, Type_data>& rhs) {
        return lhs.key < rhs.key;
    };
    friend bool operator>(const map_pair<Type_key, Type_data>& lhs,
                          const map_pair<Type_key, Type_data>& rhs) {
        return lhs.key > rhs.key;
    };
    friend bool operator==(const map_pair<Type_key, Type_data>& lhs,
                          const map_pair<Type_key, Type_data>& rhs) {
        return lhs.key == rhs.key;
    }
    friend bool operator!=(const map_pair<Type_key, Type_data>& lhs,
                           const map_pair<Type_key, Type_data>& rhs) {
        return lhs.key != rhs.key;
    }
    friend std::ostream& operator<<(std::ostream& os, const map_pair<Type_key, Type_data>& src) {
        os << src.key;
        return os;
    }
};

template<typename Type_key, typename Type_data>
class map{
private:
    Red_Black_Tree<map_pair<Type_key, Type_data>> rbt_base;
    void print();
public:
    //Default constructor
    map() = default;

    //[] operators to access data
    //Return the reference of the key related data
    Type_data& operator[](const Type_key& key);

    //Return true if the map is empty
    bool empty();

    //Return the size of the map
    unsigned int size();

    //Return true if inserted successfully
    bool insert(Type_key key, Type_data data);

    //Return true if removed successfully
    bool erase(Type_key key);

    //Clear all the elements in the map
    void clear();

    //Return a pointer to the key related data
    //If the key doesn't exist, return NULL
    Type_data* find(const Type_key& key);
};

#endif //MY_STL_MAP_H
