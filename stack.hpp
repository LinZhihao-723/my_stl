//
// Created by Pleiades Lin on 2020-08-18.
//

#ifndef MY_STL_STACK_HPP
#define MY_STL_STACK_HPP

#include "stack.h"
#include "linked_list.hpp"

template<typename Type_T>
stack<Type_T>::stack() {
    top_node = nullptr;
    stack_size = 0;
}

template<typename Type_T>
stack<Type_T>::stack(const stack<Type_T> &src) {
    top_node = copy_list(src.top_node);
    stack_size = src.stack_size;
}

template<typename Type_T>
stack<Type_T>::~stack() {
    empty();
}

template<typename Type_T>
bool stack<Type_T>::is_empty() {
    return (top_node == nullptr);
}

template<typename Type_T>
unsigned int stack<Type_T>::size() {
    return stack_size;
}

template<typename Type_T>
Type_T stack<Type_T>::top() {
    return top_node->data;
}

template<typename Type_T>
void stack<Type_T>::pop() {
    if(top_node == nullptr) return;
    List_Node<Type_T>* temp = top_node;
    top_node = top_node->next;
    -- stack_size;
    delete temp;
}

template<typename Type_T>
void stack<Type_T>::push(Type_T element) {
    List_Node<Type_T>* new_top = new List_Node<Type_T>(element);
    new_top->next = top_node;
    top_node = new_top;
    ++ stack_size;
}

template<typename Type_T>
void stack<Type_T>::empty() {
    List_Node<Type_T>* temp;
    while(top_node != nullptr) {
        temp = top_node->next;
        delete top_node;
        top_node = temp;
    }
    stack_size = 0;
}

template<typename Type_T>
stack<Type_T> &stack<Type_T>::operator=(const stack<Type_T> &src) {
    if(this != &src) {
        empty();
        top_node = copy_list(src.top_node);
        stack_size = src.stack_size;
    }
    return (*this);
}

#endif //MY_STL_STACK_HPP
