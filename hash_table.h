//
// Created by Lin Zhihao
/*
 * This file implements a hash table template.
 * Base: linked list.
 * Supported:
 *  1. Constructor(default, copy), destructor, and "=" operator.
 *  2. Size of the hash table is dynamically recorded.
 *  3. Insert, remove, and search operations.
 *  4. Automatically rehash based on the hash policy
 *  5. Allow users to reserve the bucket size
 *  Note:
 *  The key type must have its "==" operator defined.
 *  Rehash policy:
 *      load factor = size of table / size of bucket
 *      When load factor is greater than the pre-defined maximum load factor
 *      The bucket size will automatically grow: the new bucket size will be the smallest number in the prime list
 *      that larger than the current bucket size.
 */

#ifndef MY_STL_HASH_TABLE_H
#define MY_STL_HASH_TABLE_H
#include "pair.h"
#include "linked_list.h"
#include "hash_constant.h"
#include <iostream>

template<typename Type_key>
hash_key evaluate_hash_key(const Type_key& src);

template<typename Type_key, typename Type_data>
struct hash_pair : public pair<Type_key, Type_data> {
    hash_pair() = default;
    hash_pair(Type_key _key) : pair<Type_key, Type_data>::pair(_key) {};
    hash_pair(Type_key _key, Type_data _data) : pair<Type_key, Type_data>::pair(_key, _data) {};
    hash_key hash() const;
};

template<typename Type_key, typename Type_data>
class hash_table{
private:

    //The number of elements stored in the hash table
    unsigned int _size;

    //The number of bucket
    bucket_size_t _bucket_count;

    //The hash table
    List_Node<hash_pair<Type_key, Type_data>>** _table;

    //Create and initialize a hash table
    List_Node<hash_pair<Type_key, Type_data>>** initialize_table(bucket_size_t bucket_count);

    //Re_hash the hash table with the new bucket number
    void rehash(bucket_size_t new_bucket_count);

    //Evaluate the hash value of a given key
    bucket_size_t evaluate_hash_value(const Type_key &key, bucket_size_t given_bucket_count) const;

    //Find the smallest number in the prime list that larger than the current bucket number
    bucket_size_t next_prime_num() const;

    //Free the memory of the table
    void free_table();

public:

    //Constructor, destructor, and "=" operator
    hash_table();
    hash_table(const hash_table<Type_key, Type_data>& src);
    hash_table<Type_key, Type_data>& operator=(const hash_table<Type_key, Type_data>& rhs);
    ~hash_table();

    //Return the size of the table
    unsigned int size() const;

    //Return the current load factor
    float load_factor() const;

    //Return the bucket size
    bucket_size_t bucket_count() const;

    //Return the maximum bucket size that allowed
    bucket_size_t max_bucket_count() const;

    //Return true if the table is empty, false otherwise
    bool empty() const;

    //Clear all the elements in the table
    //This will not change the bucket size
    void clear();

    //Insert a new element to the table
    //Return true if success
    //Return false if the key has already existed
    bool insert(const hash_pair<Type_key, Type_data>& src);

    //Remove the element that matches the given key
    //Return true if success
    //Return false if the key not found
    bool remove(const Type_key& key);

    //Search the element that matches the given key
    //Return nullptr if not found
    List_Node<hash_pair<Type_key, Type_data>>* search(const Type_key& key) const;

    //Print the hash table
    void print_hash_table() const;

    //Update and re_hash the table with the new bucket size
    //If the new bucket size is smaller than the current one
    //Or the bucket size has reached the maximum
    //It will return directly
    void reserve(bucket_size_t new_bucket_count);
};

#endif //MY_STL_HASH_TABLE_H
