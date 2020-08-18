cmake_minimum_required(VERSION 3.16)
project(my_stl)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_stl main.cpp constant.h linked_list.h stack.h stack.hpp linked_list.hpp)