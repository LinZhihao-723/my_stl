#include <iostream>
#include "containers.h"
#include "unordered_map.hpp"
#include <cmath>

int main() {
    unordered_map<int, int> test;
    test.insert(1, 1);
    test[1] = 2;
    std::cout << test.size() << std::endl;
    std::cout << *test.find(1) << std::endl;
    return 0;
}
