#include <iostream>
#include "containers.h"
#include "hash_table.hpp"
#include <cmath>

int main() {
    hash_table<int, int> test_ht;

    for(int i = 1000; i < 1100; ++ i) {
        test_ht.insert({i, 0});
        test_ht.print_hash_table();
    }

    return 0;
}
