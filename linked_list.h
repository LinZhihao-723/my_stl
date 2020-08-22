//
// Created by Lin Zhihao
/*
 * This file implements simple linked list.
 * Supported:
 * 1. Node constructors.
 * 2. List copy.
 */

#ifndef MY_STL_LINKED_LIST_H
#define MY_STL_LINKED_LIST_H

template<typename Type_T>
struct List_Node {
    Type_T data;
    List_Node* next;
    List_Node() {
        next = nullptr;
    }
    List_Node(const Type_T& src) {
        data = src;
        next = nullptr;
    }
};

template<typename Type_T>
List_Node<Type_T> * copy_list(List_Node<Type_T> *src);

#endif //MY_STL_LINKED_LIST_H
