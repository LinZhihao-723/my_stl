//
// Created by Lin Zhihao

#include "guard.h"
#include <iostream>

void check_null_pointer(void* ptr) {
    if(ptr == nullptr) {
        std::cout << "Segmentation Fault!" << std::endl;
        exit(SEGMENTATION_FAULT);
    }
    return;
}

void check_access_violation(void* ptr) {
    if(ptr == nullptr) {
        std::cout << "Access Violation!" << std::endl;
        exit(ACCESS_VIOLATION);
    }
}

void access_violation() {
    std::cout << "Access Violation!" << std::endl;
    exit(ACCESS_VIOLATION);
}