cmake_minimum_required(VERSION 3.16)
project(my_stl)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_stl main.cpp constant.h linked_list.h stack.h stack.hpp linked_list.hpp queue.h queue.hpp queue.h guard.h guard.cpp red_black_tree.h red_black_tree.hpp set.h set.hpp containers.h map.h map.hpp vector.h vector.hpp pair.h hash_table.h hash_table.hpp hash_constant.h binary_heap.h binary_heap.hpp unordered_map.hpp unordered_map.h priority_queue.h priority_queue.hpp)