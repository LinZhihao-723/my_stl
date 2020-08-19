//
// Created by Lin Zhihao

#ifndef MY_STL_SET_HPP
#define MY_STL_SET_HPP
#include "set.h"

template<typename Type_T>
set<Type_T>::set() {
    //All by default.
}

template<typename Type_T>
set<Type_T>::set(const set<Type_T> &src) {
    rbt_base = src.rbt_base;
}

template<typename Type_T>
set<Type_T>::~set() {
    rbt_base.empty();
}

template<typename Type_T>
set<Type_T> &set<Type_T>::operator=(const set<Type_T> &rhs) {
    if(this != &rhs) {
        rbt_base = rhs.rbt_base;
    }
    return *this;
}

template<typename Type_T>
bool set<Type_T>::is_empty() {
    return rbt_base.is_empty();
}

template<typename Type_T>
unsigned int set<Type_T>::size() {
    return rbt_base.size();
}

template<typename Type_T>
void set<Type_T>::clear() {
    rbt_base.empty();
}

template<typename Type_T>
void set<Type_T>::insert(Type_T key) {
    rbt_base.insert(key);
}

template<typename Type_T>
void set<Type_T>::erase(Type_T key) {
    rbt_base.remove(key);
}

template<typename Type_T>
bool set<Type_T>::find(Type_T key) {
    return rbt_base.search(key) != nullptr;
}

template<typename Type_T>
bool set<Type_T>::modify(Type_T old_key, Type_T new_key) {
    if(rbt_base.remove(old_key)) {
        rbt_base.insert(new_key);
        return true;
    } else {
        return false;
    }
}

#endif //MY_STL_SET_HPP
