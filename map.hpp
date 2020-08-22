//
// Created by Lin Zhihao
/*"念念不忘，必有回响"*/

#ifndef MY_STL_MAP_HPP
#define MY_STL_MAP_HPP
#include "map.h"
#include "iostream"

template<typename Type_key, typename Type_data>
Type_data &map<Type_key, Type_data>::operator[](const Type_key &key) const {
    TreeNode<pair<Type_key, Type_data>>* search_result = rbt_base.search(key);
    check_access_violation(search_result);
    return (search_result->data).data;
}

template<typename Type_key, typename Type_data>
bool map<Type_key, Type_data>::empty() const {
    return rbt_base.is_empty();
}

template<typename Type_key, typename Type_data>
unsigned int map<Type_key, Type_data>::size() const {
    return rbt_base.size();
}

template<typename Type_key, typename Type_data>
bool map<Type_key, Type_data>::insert(Type_key key, Type_data data) {
    return rbt_base.insert({key, data});
}

template<typename Type_key, typename Type_data>
bool map<Type_key, Type_data>::erase(const Type_key& key) {
    return rbt_base.remove(key);
}

template<typename Type_key, typename Type_data>
void map<Type_key, Type_data>::clear() {
    rbt_base.empty();
}

template<typename Type_key, typename Type_data>
Type_data *map<Type_key, Type_data>::find(const Type_key &key) const {
    return rbt_base.search(key);
}

template<typename Type_key, typename Type_data>
void map<Type_key, Type_data>::print() const {
    rbt_base.print_tree();
}

#endif //MY_STL_MAP_HPP
