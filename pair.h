//
// Created by Pleiades Lin on 2020-08-20.
//

#ifndef MY_STL_PAIR_H
#define MY_STL_PAIR_H
//This structure is used to store values of map in the red black tree.
//Operators are overloaded for the red black tree operations.
template<typename Type_key, typename Type_data>
struct pair{
    Type_key key;
    Type_data data;
    pair() = default;
    pair(Type_key _key): key(_key) {};
    pair(Type_key _key, Type_data _data): key(_key), data(_data) {};
    friend bool operator<(const pair<Type_key, Type_data>& lhs,
                          const pair<Type_key, Type_data>& rhs) {
        return lhs.key < rhs.key;
    };
    friend bool operator>(const pair<Type_key, Type_data>& lhs,
                          const pair<Type_key, Type_data>& rhs) {
        return lhs.key > rhs.key;
    };
    friend bool operator==(const pair<Type_key, Type_data>& lhs,
                           const pair<Type_key, Type_data>& rhs) {
        return lhs.key == rhs.key;
    }
    friend bool operator!=(const pair<Type_key, Type_data>& lhs,
                           const pair<Type_key, Type_data>& rhs) {
        return lhs.key != rhs.key;
    }
    friend std::ostream& operator<<(std::ostream& os, const pair<Type_key, Type_data>& src) {
        os << src.key;
        return os;
    }
};
#endif //MY_STL_PAIR_H
