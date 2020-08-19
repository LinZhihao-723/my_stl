cmake_minimum_required(VERSION 3.16)
project(my_stl)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_stl main.cpp constant.h linked_list.h stack.h stack.hpp linked_list.hpp queue.h queue.hpp queue.h guard.h guard.cpp red_black_tree.h red_black_tree.hpp RBT_Test.h RBT_Test.cpp ground_level_structure_headers.h set.h set.hpp containers.h)