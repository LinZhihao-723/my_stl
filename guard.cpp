//
// Created by Lin Zhihao

#include "guard.h"
#include <iostream>

void check_null_pointer(void* ptr) {
    if(ptr == nullptr) {
        std::cout << "Attempt to access NULL pointer!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return;
}