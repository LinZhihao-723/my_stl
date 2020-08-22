//
// Created by Lin Zhihao

#ifndef MY_STL_PRIORITY_QUEUE_HPP
#define MY_STL_PRIORITY_QUEUE_HPP
#include "priority_queue.h"

template<typename Type_T>
unsigned int priority_queue<Type_T>::size() const {
    return _heap.size();
}

template<typename Type_T>
bool priority_queue<Type_T>::empty() const {
    return _heap.empty();
}

template<typename Type_T>
Type_T priority_queue<Type_T>::top() const {
    return _heap.top();
}

template<typename Type_T>
void priority_queue<Type_T>::insert(const Type_T &src) {
    _heap.insert(src);
}

template<typename Type_T>
void priority_queue<Type_T>::pop() {
    _heap.pop();
}

template<typename Type_T>
void priority_queue<Type_T>::clear() {
    _heap.clear();
}

#endif //MY_STL_PRIORITY_QUEUE_HPP
