//
// Created by Pleiades Lin on 2020-08-18.
//

#ifndef MY_STL_LINKED_LIST_H
#define MY_STL_LINKED_LIST_H

template<typename Type_T>
struct List_Node {
    Type_T data;
    List_Node* next;
    List_Node() {
        next = nullptr;
    }
    List_Node(Type_T src) {
        data = src;
        next = nullptr;
    }
};

template<typename Type_T>
List_Node<Type_T> * copy_list(List_Node<Type_T> *src);



#endif //MY_STL_LINKED_LIST_H
