//
// Created by Pleiades Lin on 2020-08-19.
//
#include "RBT_Test.h"
#include <vector>
#include <algorithm>

void rbt_test() {
    Red_Black_Tree<int> test_tree;
    std::vector<int> nums(50, 0);
    for(int i = 0; i < 50; ++ i) nums[i] = i;
    //std::random_shuffle(nums.begin(), nums.end());

    for(int i : nums) test_tree.insert(nums[i]);

    auto key = test_tree.search(50);
    if(key != nullptr) std::cout << "The key is: " << key->data << std::endl;

    for(int i = 0; i < 50; ++ i) {
//        if(i % 2 == 0) test_tree.remove(nums[i]);
//        else test_tree.remove(nums[49 - i]);
        test_tree.remove(i);
    }

    test_tree.print_tree();
}
