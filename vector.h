//
// Created by Lin Zhihao
/*
 * This file implements a vector template.
 * Base: dynamic array (in the heap)
 * Supported:
 *  1. Constructor(three different versions, copy), destructor, "[]" and "=" operator.
 *  2. Direct access to any element in the vector with linear time complexity.
 *  3. Size automatically crowing.
 */

#ifndef MY_STL_VECTOR_H
#define MY_STL_VECTOR_H

#include "guard.h"
#include <cstring>

#define GROWTH_RATE 2

template<typename Type_T>
class vector{
private:
    Type_T* mem_first;
    Type_T* mem_last;
    Type_T* mem_end;

    bool allocate(unsigned int _capacity);
    bool re_allocate(unsigned int _capacity);

public:

    //Constructors:
    vector();
    vector(unsigned int size);
    vector(unsigned int size, const Type_T& src);
    vector(const vector<Type_T>& src);

    //Operator overloading:
    vector<Type_T>& operator=(const vector<Type_T>& rhs);
    Type_T& operator[](int index) const;

    //Destructor:
    ~vector();

    //Return the size of the vector
    unsigned int size() const;

    //Return the capacity of the vector
    unsigned int capacity() const;

    //Return true if the vector is empty
    bool empty() const;

    //Insert an element at the end of the vector
    bool push_back(const Type_T& src);

    //Remove the last element in the vector
    bool pop_back();

    //Remove the element at the end of the vector
    //Return true if success
    bool erase(int index);

    //Remove all the elements in the vector
    void clear();

    //Resize the vector
    //Keep the first n elements if the new size n is smaller than the old size
    void resize(unsigned int _size, const Type_T& src);

    //Reserve more space
    //It will create a new space if necessary
    void reserve(unsigned int _capacity);

};
#endif //MY_STL_VECTOR_H
