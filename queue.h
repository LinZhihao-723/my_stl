//
// Created by Lin Zhihao
/*
 * This file implements a queue template.
 * Base: linked list.
 * Supported:
 *  1. Constructor(default, copy), destructor, and "=" operator.
 *  2. Size of the queue is dynamically recorded.
 *  3. Push and pop operations.
 *  4. Access to the front and back elements.
 */

#ifndef MY_STL_QUEUE_H
#define MY_STL_QUEUE_H
#include "ground_level_structure_headers.h"

template<typename Type_T>
class queue{
private:
    //private pointer: the dummy head of the queue
    List_Node<Type_T>* head_node;

    //private pointer: the tail of the queue
    List_Node<Type_T>* tail_node;

    //recording the size of the queue
    unsigned int queue_size;

    //Helper function: find the tail from the head
    List_Node<Type_T>* track_tail();
public:
    //Default constructor.
    queue();

    //Copy constructor.
    queue(const queue<Type_T> &src);

    //Destructor.
    ~queue();

    //"=" overload
    queue<Type_T>& operator = (const queue<Type_T> &src);

    //Return if the queue is empty.
    bool is_empty();

    //Return the size of the queue.
    unsigned int size();

    //Return the front of the queue.
    Type_T front();

    //Return the back of the queue.
    Type_T back();

    //Pop the front node.
    void pop_front();

    //Push elements to the end of the queue.
    void push_back(Type_T element);

    //Empty the entire queue.
    void empty();
};

#endif //MY_STL_QUEUE_H
