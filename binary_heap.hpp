//
// Created by Lin Zhihao

#ifndef MY_STL_BINARY_HEAP_HPP
#define MY_STL_BINARY_HEAP_HPP
#include "binary_heap.h"

template<typename Type_T>
binary_heap<Type_T>::binary_heap() : _heap(1, Type_T()) {

}

template<typename Type_T>
bool binary_heap<Type_T>::empty() const {
    return _heap.size() == 1;
}

template<typename Type_T>
unsigned int binary_heap<Type_T>::size() const {
    return _heap.size() - 1;
}

template<typename Type_T>
void binary_heap<Type_T>::clear() {
    _heap.resize(1, Type_T());
}

template<typename Type_T>
Type_T binary_heap<Type_T>::top() const {
    if(empty()) {
        access_violation();
    }
    return _heap[1];
}

template<typename Type_T>
void binary_heap<Type_T>::insert(const Type_T &src) {
    _heap.push_back(src);
    unsigned int up_rearrange = size();
    while((up_rearrange / 2) != 0 && _heap[up_rearrange] > _heap[up_rearrange / 2]) {
        swap(_heap[up_rearrange], _heap[up_rearrange / 2]);
        up_rearrange = up_rearrange / 2;
    }
}


template<typename Type_T>
void binary_heap<Type_T>::pop() {
    if(empty()) {
        return;
    }
    swap(_heap[size()], _heap[1]);
    _heap.erase(size());
    unsigned int down_rearrange = 1;
    while(true) {
        if(down_rearrange >= _heap.size() || down_rearrange * 2 >= _heap.size()) {
            break;
        } else if(down_rearrange * 2 + 1 >= _heap.size()) {
            if(_heap[down_rearrange * 2] > _heap[down_rearrange]) {
                swap(_heap[down_rearrange], _heap[down_rearrange * 2]);
            }
            break;
        } else {
            unsigned int next_rearrange = _heap[down_rearrange * 2] > _heap[down_rearrange * 2 + 1] ?
                    down_rearrange * 2 : down_rearrange * 2 + 1;
            if(_heap[next_rearrange] > _heap[down_rearrange]) {
                swap(_heap[next_rearrange], _heap[down_rearrange]);
                down_rearrange = next_rearrange;
            } else {
                break;
            }
        }
    }
}

template<typename Type_T>
void binary_heap<Type_T>::swap(Type_T &a, Type_T &b) {
    Type_T temp = a;
    a = b;
    b = temp;
}

#endif //MY_STL_BINARY_HEAP_HPP
