//
// Created by Lin Zhihao
/*
 * This file implements a stack template.
 * Base: linked list.
 * Supported:
 *  1. Constructor(default, copy), destructor, and "=" operator.
 *  2. Size of the stack is dynamically recorded.
 *  3. Push and pop operations.
 *  4. Access to the top element.
 */

#ifndef MY_STL_STACK_H
#define MY_STL_STACK_H
#include "ground_level_structure_headers.h"

template<typename Type_T>
class stack{
private:
    //private pointer which maintains a linked list.
    List_Node<Type_T>* top_node;

    //recording the size of the stack
    unsigned int stack_size;
public:
    //Default constructor.
    stack();

    //Copy constructor.
    stack(const stack<Type_T> &src);

    //Destructor.
    ~stack();

    //"=" overload
    stack<Type_T>& operator = (const stack<Type_T> &src);

    //Return if the stack is empty.
    bool is_empty();

    //Return the size of the stack.
    unsigned int size();

    //Return the top of the stack.
    Type_T top();

    //Pop the top node.
    void pop();

    //Push elements to the stack.
    void push(Type_T element);

    //Empty the entire stack.
    void empty();
};

#endif //MY_STL_STACK_H
