//
// Created by Pleiades Lin on 2020-08-18.
//

#ifndef MY_STL_QUEUE_HPP
#define MY_STL_QUEUE_HPP
#include "queue.h"
#include "guard.h"

template<typename Type_T>
queue<Type_T>::queue() {
    queue_size = 0;
    head_node = tail_node = nullptr;
}

template<typename Type_T>
queue<Type_T>::queue(const queue<Type_T> &src) {
    queue_size = src.queue_size;
    head_node = copy_list(src.head_node);
    tail_node = track_tail();
}

template<typename Type_T>
queue<Type_T>::~queue() {
    empty();
}

template<typename Type_T>
queue<Type_T> &queue<Type_T>::operator=(const queue<Type_T> &src) {
    if(this != &src) {
        empty();
        head_node = copy_list(src.head_node);
        tail_node = track_tail();
        queue_size = src.queue_size;
    }
    return *this;
}

template<typename Type_T>
bool queue<Type_T>::is_empty() {
    return (head_node == nullptr);
}

template<typename Type_T>
unsigned int queue<Type_T>::size() {
    return queue_size;
}

template<typename Type_T>
Type_T queue<Type_T>::front() {
    check_null_pointer(head_node);
    return head_node->data;
}

template<typename Type_T>
Type_T queue<Type_T>::back() {
    check_null_pointer(tail_node);
    return tail_node->data;
}

template<typename Type_T>
void queue<Type_T>::pop_front() {
    check_null_pointer(head_node);
    List_Node<Type_T>* new_head = head_node->next;
    delete head_node;
    head_node = new_head;
    -- queue_size;
    if(head_node == nullptr) tail_node = nullptr;
}

template<typename Type_T>
void queue<Type_T>::push_back(Type_T element) {
    List_Node<Type_T>* temp = new List_Node<Type_T>(element);
    if(is_empty()) {
        head_node = tail_node = temp;
    } else {
        tail_node = tail_node->next = temp;
    }
    ++ queue_size;
}

template<typename Type_T>
void queue<Type_T>::empty() {
    List_Node<Type_T>* temp;
    while(head_node != nullptr) {
        temp = head_node;
        head_node = head_node->next;
        delete temp;
    }
    tail_node = head_node;
    queue_size = 0;
}

template<typename Type_T>
List_Node<Type_T> *queue<Type_T>::track_tail() {
    List_Node<Type_T> *current = head_node;
    while(current != nullptr && current->next != nullptr) {
        current = current->next;
    }
    return current;
}
#endif //MY_STL_QUEUE_HPP
