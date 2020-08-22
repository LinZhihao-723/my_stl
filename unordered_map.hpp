//
// Created by Lin Zhihao

#ifndef MY_STL_UNORDERED_MAP_HPP
#define MY_STL_UNORDERED_MAP_HPP
#include "unordered_map.h"

template<typename Type_key, typename Type_data>
Type_data &unordered_map<Type_key, Type_data>::operator[](const Type_key &key) const {
    List_Node<hash_pair<Type_key, Type_data>>* search_result = _hash_table.search(key);
    check_access_violation(search_result);
    //if(search_result == nullptr) {
    //    _hash_table.insert({key, Type_data()});
    //}
    return (search_result->data).data;
}

template<typename Type_key, typename Type_data>
bool unordered_map<Type_key, Type_data>::empty() const {
    return _hash_table.empty();
}

template<typename Type_key, typename Type_data>
unsigned int unordered_map<Type_key, Type_data>::size() const {
    return _hash_table.size();
}

template<typename Type_key, typename Type_data>
bool unordered_map<Type_key, Type_data>::insert(Type_key key, Type_data data) {
    return _hash_table.insert({key, data});
}

template<typename Type_key, typename Type_data>
bool unordered_map<Type_key, Type_data>::erase(const Type_key& key) {
    return _hash_table.remove(key);
}

template<typename Type_key, typename Type_data>
void unordered_map<Type_key, Type_data>::clear() {
    _hash_table.clear();
}

template<typename Type_key, typename Type_data>
Type_data *unordered_map<Type_key, Type_data>::find(const Type_key &key) const {
    return &((_hash_table.search(key)->data).data);
}

#endif //MY_STL_UNORDERED_MAP_HPP
