#include <iostream>
#include "containers.h"
#include "binary_heap.hpp"
#include <cmath>
#include <vector>
#include <algorithm>

int main() {
    //binary_heap<std::string> test;
    std::vector<int> nums(100, 0);
    for(int i = 0; i < 100; ++ i) {
        nums[i] = i / 2;
    }
    random_shuffle(nums.begin(), nums.end());
    binary_heap<int> test;
    for(int i : nums) {
        test.insert(i);
    }
    binary_heap<int> test_2;
    test_2 = test;
    while(!test_2.empty()) {
        std::cout << test_2.top() << " " << test_2.size() << std::endl;
        test_2.pop();
    }
    std::cout << test.size() << " " << test_2.size() << std::endl;
    return 0;
}
