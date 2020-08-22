//
// Created by Lin Zhihao
/*
 * This file implements a binary heap template.
 * Base: vector.
 * Supported:
 *  1. Constructor(default, copy), destructor, and "=" operator.
 *  2. Access to the top element which is guaranteed to be the largest element in the heap.
 *  3. Insert, remove operations which maintains the heap property.
 *  Note:
 *  1. The type being stored must have its ">" operator defined.
 *  2. The type being stored must have its default constructor defined.
 */

#ifndef MY_STL_BINARY_HEAP_H
#define MY_STL_BINARY_HEAP_H
#include "vector.hpp"
#include "guard.h"

template<typename Type_T>
class binary_heap {
private:

    //The base of the binary heap is a vector
    vector<Type_T> _heap;

    //Swap two elements
    void swap(Type_T& a, Type_T& b);

public:

    //Default constructor
    binary_heap();

    //Return true if the heap is empty, false otherwise
    bool empty() const;

    //Return the size of the heap
    unsigned int size() const;

    //Clear all the elements in the heap
    void clear();

    //Return the largest value stored in the heap
    Type_T top() const;

    //Insert an element
    void insert(const Type_T& src);

    //Remove the largest element from the heap
    void pop();

};

#endif //MY_STL_BINARY_HEAP_H
