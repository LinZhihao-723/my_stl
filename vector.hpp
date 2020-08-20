//
// Created by Lin Zhihao

#ifndef MY_STL_VECTOR_HPP
#define MY_STL_VECTOR_HPP
#include "vector.h"
template<typename Type_T>
vector<Type_T>::vector() {
    allocate(0);
}

template<typename Type_T>
vector<Type_T>::vector(unsigned int size) {
    allocate(size);
}

template<typename Type_T>
vector<Type_T>::vector(unsigned int size, const Type_T &src) {
    allocate(size);
    for(int i = 0; i < size; ++ i) {
        *mem_last = src;
        ++ mem_last;
    }
}

template<typename Type_T>
vector<Type_T>::vector(const vector<Type_T> &src) {
    allocate(src.capacity());
    for(Type_T* current = src.mem_first; current != src.mem_last; ++ current) {
        *mem_last = *current;
        ++ mem_last;
    }
}

template<typename Type_T>
vector<Type_T> &vector<Type_T>::operator=(const vector<Type_T> &rhs) {
    if(this != &rhs) {
        delete [] mem_first;
        allocate(rhs.capacity());
        for(Type_T* current = rhs.mem_first; current != rhs.mem_last; ++ current) {
            *mem_last = *current;
            ++ mem_last;
        }
    }
    return *this;
}

template<typename Type_T>
Type_T &vector<Type_T>::operator[](int index) const {
    if(index >= size()) {
        access_violation();
    }
    return *(mem_first + index);
}

template<typename Type_T>
vector<Type_T>::~vector() {
    delete [] mem_first;
}

template<typename Type_T>
unsigned int vector<Type_T>::size() const {
    return mem_last - mem_first;
}

template<typename Type_T>
unsigned int vector<Type_T>::capacity() const {
    return mem_end - mem_first;
}

template<typename Type_T>
bool vector<Type_T>::empty() const {
    return mem_last == mem_first;
}

template<typename Type_T>
bool vector<Type_T>::push_back(const Type_T &src) {
    if(mem_last == mem_end) {
        re_allocate(capacity() == 0 ? 1 : GROWTH_RATE * capacity());
    }
    *(mem_last ++) = src;
    return true;
}

template<typename Type_T>
bool vector<Type_T>::pop_back() {
    -- mem_last;
    return true;
}

template<typename Type_T>
bool vector<Type_T>::erase(int index) {
    if(index >= size()) {
        access_violation();
        return false;
    }
    -- mem_last;
    for(Type_T* current = mem_first + index; current != mem_last; ++ current) {
        *current = *(current + 1);
    }
    return true;
}

template<typename Type_T>
void vector<Type_T>::clear() {
    mem_last = mem_first;
}

template<typename Type_T>
void vector<Type_T>::resize(unsigned int _size, const Type_T& src) {
    Type_T* new_mem_first = new Type_T [_size];
    for(int i = 0; i < _size; ++ i) {
        new_mem_first[i] = i < size() ?
                *(mem_first + i) : src;
    }
    delete [] mem_first;
    mem_first = new_mem_first;
    mem_end = mem_last = mem_first + _size;
}

template<typename Type_T>
void vector<Type_T>::reserve(unsigned int _capacity) {
    if(_capacity <= capacity()) {
        return;
    } else {
        re_allocate(_capacity);
    }
}

template<typename Type_T>
bool vector<Type_T>::allocate(unsigned int _capacity) {
    mem_first = mem_last = mem_end = nullptr;
    if(_capacity == 0) {
        return false;
    } else {
        mem_first = new Type_T [_capacity];
        mem_last = mem_first;
        mem_end = mem_first + _capacity;
        return true;
    }
}

template<typename Type_T>
bool vector<Type_T>::re_allocate(unsigned int _capacity) {
    //It is guaranteed that the new capacity is larger than the old capacity
    //Which means it is safe to copy memory
    if(_capacity == 0) {
        return false;
    } else {
        unsigned int _size = size();
        Type_T* new_mem_first = new Type_T [_capacity];
        memcpy(new_mem_first, mem_first, _size * sizeof(Type_T));
        delete [] mem_first;
        mem_first = new_mem_first;
        mem_last = mem_first + _size;
        mem_end = mem_first + _capacity;
        return true;
    }
}
#endif //MY_STL_VECTOR_HPP
