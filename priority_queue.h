//
// Created by Lin Zhihao
/*
 * This file implements an priority queue template.
 * Base: binary heap.
 * Supported:
 *  1. Insert elements to the queue, the value does not have to be identical.
 *  2. Pop element from the top.
 *  3. Return the value of the largest element in the queue (top).
 *  Note:
 *  The type being stored must have its ">" operator defined.
 */

#ifndef MY_STL_PRIORITY_QUEUE_H
#define MY_STL_PRIORITY_QUEUE_H
#include "binary_heap.hpp"

template<typename Type_T>
class priority_queue{
private:
    //The base: a binary heap
    binary_heap<Type_T> _heap;

public:
    //Default constructor
    priority_queue() = default;

    //Return the size of the priority queue
    unsigned int size() const;

    //Return true if the priority queue is empty, false otherwise
    bool empty() const;

    //Return the value of the top element
    Type_T top() const;

    //Insert an element to the priority queue
    void insert(const Type_T& src);

    //Pop the top element from the priority queue
    void pop();

    //Remove all the elements from the priority queue
    void clear();
};
#endif //MY_STL_PRIORITY_QUEUE_H
