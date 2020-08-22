//
// Created by Lin Zhihao
/*"烽火燃不息，征战无已时"*/

#ifndef MY_STL_LINKED_LIST_HPP
#define MY_STL_LINKED_LIST_HPP
#include "linked_list.h"

template<typename Type_T>
List_Node<Type_T> *copy_list(List_Node<Type_T> *src) {
    List_Node<Type_T>* dest = nullptr;
    List_Node<Type_T>** tracker = &dest;
    while(src != nullptr) {
        *tracker = new List_Node<Type_T>(src->data);
        tracker = &((*tracker)->next);
        src = src->next;
    }
    *tracker = nullptr;
    return dest;
}

#endif //MY_STL_LINKED_LIST_HPP
