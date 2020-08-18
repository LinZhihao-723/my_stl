//
// Created by Pleiades Lin on 2020-08-18.
//

#ifndef MY_STL_STACK_H
#define MY_STL_STACK_H

#include "linked_list.h"

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
    stack(stack<Type_T> &src);

    //Destructor.
    ~stack();

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
