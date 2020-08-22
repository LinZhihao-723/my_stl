//
// Created by Lin Zhihao

#ifndef MY_STL_HASH_TABLE_HPP
#define MY_STL_HASH_TABLE_HPP
#include "hash_table.h"

template<typename Type_key>
hash_key evaluate_hash_key(const Type_key &src) {
    //Hash function
    //Treat each single byte as a integer
    hash_key hash_value = 0;
    char* start = (char*) &(src);
    for(int i = 0; i < sizeof(Type_key); ++ i) {
        hash_value = 4 * hash_value + *(start + i);
    }
    return hash_value;
}

template<typename Type_key, typename Type_data>
hash_key hash_pair<Type_key, Type_data>::hash() const {
    return evaluate_hash_key(hash_pair<Type_key, Type_data>::key);
}

template<typename Type_key, typename Type_data>
hash_table<Type_key, Type_data>::hash_table() {
    //Initialize the hash table
    //The default bucket count is 2, which is the first prime number
    _size = 0;
    _bucket_count = prime_list[0];
    _table = initialize_table(_bucket_count);
}

template<typename Type_key, typename Type_data>
hash_table<Type_key, Type_data>::hash_table(const hash_table<Type_key, Type_data> &src) {
    _size = src._size;
    _bucket_count = src._bucket_count;
    _table = initialize_table(_bucket_count);
    for(bucket_size_t i = 0; i < _bucket_count; ++ i) {
        _table[i] = copy_list(src._table[i]);
    }
}

template<typename Type_key, typename Type_data>
hash_table<Type_key, Type_data> &hash_table<Type_key, Type_data>::operator=(const hash_table<Type_key, Type_data> &rhs){
    if(this != &rhs) {
        free_table();
        _size = rhs._size;
        _bucket_count = rhs._bucket_count;
        _table = initialize_table(_bucket_count);
        for(bucket_size_t i = 0; i < _bucket_count; ++ i) {
            _table[i] = copy_list(rhs._table[i]);
        }
    }
    return *this;
}

template<typename Type_key, typename Type_data>
hash_table<Type_key, Type_data>::~hash_table() {
    free_table();
}

template<typename Type_key, typename Type_data>
unsigned int hash_table<Type_key, Type_data>::size() const {
    return _size;
}

template<typename Type_key, typename Type_data>
bool hash_table<Type_key, Type_data>::empty() const {
    return (_size == 0);
}

template<typename Type_key, typename Type_data>
void hash_table<Type_key, Type_data>::clear() {
    //Note: this function will not change bucket count
    free_table();
    _size = 0;
    _table = initialize_table(_bucket_count);
}

template<typename Type_key, typename Type_data>
bool hash_table<Type_key, Type_data>::insert(const hash_pair<Type_key, Type_data> &src) {
    if(search(src.key) != nullptr) {
        //If the key has existed already, return false
        return false;
    }
    if(_bucket_count != max_bucket_count() && load_factor() >= MAX_LOAD_FACTOR) {
        //If the bucket count doesn't reach the max yet, and the load factor has exceeded
        //This function will find the next larger bucket in the prime list
        //And execute rehash
        bucket_size_t new_bucket_count = next_prime_num();
        rehash(new_bucket_count);
    }
    //The new element will be insert at the front
    List_Node<hash_pair<Type_key, Type_data>>* temp = new List_Node<hash_pair<Type_key, Type_data>>(src);
    bucket_size_t hash_value = evaluate_hash_value((temp->data).key, _bucket_count);
    temp->next = _table[hash_value];
    _table[hash_value] = temp;
    ++ _size;
    return true;
}

template<typename Type_key, typename Type_data>
bool hash_table<Type_key, Type_data>::remove(const Type_key &key) {
    auto target = search(key);
    if(target == nullptr) {
        //If the key does not exist, return false
        return false;
    }
    //Remove the target node from the table
    //Note: a double pointer "tracker" is used to simplify cases
    bucket_size_t hash_value = evaluate_hash_value(key, _bucket_count);
    List_Node<hash_pair<Type_key, Type_data>>** tracker = &_table[hash_value];
    while(*tracker != target) tracker = &((*tracker)->next);
    *tracker = target->next;
    delete target;
    -- _size;
    return true;
}

template<typename Type_key, typename Type_data>
List_Node<hash_pair<Type_key, Type_data>> *hash_table<Type_key, Type_data>::search(const Type_key &key) const {
    List_Node<hash_pair<Type_key, Type_data>>* current;
    for(current = _table[evaluate_hash_value(key, _bucket_count)];
        current != nullptr && !(current->data == key);
        current = current->next);
    return current;
}

template<typename Type_key, typename Type_data>
void hash_table<Type_key, Type_data>::print_hash_table() const {
    std::cout << "Number of elements: " << _size << std::endl;
    std::cout << "Bucket size: " << _bucket_count << std::endl;
    int index = 0;
    for(int i = 0; i < _bucket_count; ++ i) {
        auto current = _table[i];
        std::cout << index << ": ";
        ++ index;
        while(current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }
    std::cout << std::endl;
}

template<typename Type_key, typename Type_data>
float hash_table<Type_key, Type_data>::load_factor() const {
    //load factor = current size / current bucket count
    return ((float) _size) / _bucket_count;
}

template<typename Type_key, typename Type_data>
bucket_size_t hash_table<Type_key, Type_data>::max_bucket_count() const {
    return prime_list[PRIME_LIST_SIZE - 1];
}

template<typename Type_key, typename Type_data>
bucket_size_t hash_table<Type_key, Type_data>::bucket_count() const {
    return _bucket_count;
}

template<typename Type_key, typename Type_data>
void hash_table<Type_key, Type_data>::reserve(bucket_size_t new_bucket_count) {
    if(bucket_count() == max_bucket_count() || new_bucket_count < _bucket_count) {
        //If the bucket count has reached the maximum capacity
        //Or the new bucket count is smaller than the current one
        //Then directly return
        return;
    } else {
        //If the given new bucket count is larger than the maximum, then use the maximum value
        bucket_size_t rehash_bucket_count = new_bucket_count > max_bucket_count() ?
                max_bucket_count() : new_bucket_count;
        rehash(rehash_bucket_count);
    }
}

template<typename Type_key, typename Type_data>
void hash_table<Type_key, Type_data>::rehash(bucket_size_t new_bucket_count) {
    //Create a new table
    List_Node<hash_pair<Type_key, Type_data>>** new_table = initialize_table(new_bucket_count);

    //Copy all the node from the old table to the new table
    for(int i = 0; i < _bucket_count; ++ i) {
        auto current = _table[i];
        while(current != nullptr) {
            List_Node<hash_pair<Type_key, Type_data>>* temp =
                    new List_Node<hash_pair<Type_key, Type_data>>(current->data);
            //Hash value is calculated using new bucket count
            bucket_size_t hash_value = evaluate_hash_value((temp->data).key, new_bucket_count);
            temp->next = new_table[hash_value];
            new_table[hash_value] = temp;
            current = current->next;
        }
    }

    //Free the old table, update the bucket count and the table
    free_table();
    _bucket_count = new_bucket_count;
    _table = new_table;
}

template<typename Type_key, typename Type_data>
List_Node<hash_pair<Type_key, Type_data>>**
        hash_table<Type_key, Type_data>::initialize_table(bucket_size_t bucket_count) {
    List_Node<hash_pair<Type_key, Type_data>> **result = new List_Node<hash_pair<Type_key, Type_data>>* [bucket_count];
    for(bucket_size_t i = 0; i < bucket_count; ++ i) {
        result[i] = nullptr;
    }
    return result;
}

template<typename Type_key, typename Type_data>
void hash_table<Type_key, Type_data>::free_table() {
    for(int i = 0; i < _bucket_count; ++ i) {
        auto current = _table[i];
        while(current != nullptr) {
            auto temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete [] _table;
}

template<typename Type_key, typename Type_data>
bucket_size_t
hash_table<Type_key, Type_data>::evaluate_hash_value(const Type_key &key, bucket_size_t given_bucket_count) const {
    return evaluate_hash_key(key) % given_bucket_count;
}

template<typename Type_key, typename Type_data>
bucket_size_t hash_table<Type_key, Type_data>::next_prime_num() const {
    for(bucket_size_t i : prime_list) {
        if(i > _bucket_count) return i;
    }
    return max_bucket_count();
}

#endif //MY_STL_HASH_TABLE_HPP
