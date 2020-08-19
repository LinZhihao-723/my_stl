//
// Created by Pleiades Lin on 2020-08-19.
//
#include "RBT_Test.h"

void rbt_test() {
    Red_Black_Tree<int> test_tree;
    for(int i = 0; i < 10; ++ i) test_tree.insert(i);
    test_tree.print_tree();
    Red_Black_Tree<int> test_tree_copied;
    test_tree_copied = test_tree;
    test_tree.print_tree();
}
