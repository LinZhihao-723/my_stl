//
// Created by Lin Zhihao
/*
 * This file implements a set template.
 * Base: red black tree.
 * Supported:
 *  1. Constructor(default, copy), destructor, and "=" operator.
 *  2. Size of the set is dynamically recorded.
 *  3. Insert/remove elements from the set.
 *  4. Check if a key is stored.
 *  5. Modify the existing key.
 *
 *  Traversing will be implemented soon.
 */

#ifndef MY_STL_SET_H
#define MY_STL_SET_H
#include "red_black_tree.hpp"

template<typename Type_T>
class set{
private:
    Red_Black_Tree<Type_T> rbt_base;
public:
    //Default constructor
    set();

    //Copy constructor
    set(const set<Type_T>& src);

    //Destructor
    ~set();

    //= sign
    set<Type_T>& operator=(const set<Type_T>& rhs);

    //Return true if the set is empty
    bool is_empty();

    //Return the size of the set
    unsigned int size();

    //clear all the elements in the set
    void clear();

    //Insert a key
    void insert(Type_T key);

    //Erase a key
    void erase(Type_T key);

    //Return true if the key exists, otherwise return false
    bool find(Type_T key);

    //Modify the old key with the new key
    //Return true if success
    //Return false if the old key does not exist
    bool modify(Type_T old_key, Type_T new_key);
};
#endif //MY_STL_SET_H
