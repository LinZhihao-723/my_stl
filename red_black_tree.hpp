//
// Created by Lin Zhihao

#ifndef MY_STL_RED_BLACK_TREE_HPP
#define MY_STL_RED_BLACK_TREE_HPP
#include <iostream>
#include "red_black_tree.h"

template<typename Type_T>
bool Red_Black_Tree<Type_T>::is_black(TreeNode<Type_T> *current) {
    return current == nullptr || current->color == BLACK;
}

template<typename Type_T>
bool Red_Black_Tree<Type_T>::rotate_left(TreeNode<Type_T> *current) {
    if(current->right == nullptr) return false;
    TreeNode<Type_T>* right_side = current->right;
    //Setting the parent node
    if(current->parent == nullptr) {
        root = right_side;
    } else {
        if(current->parent->left == current) {
            current->parent->left = right_side;
        } else {
            current->parent->right = right_side;
        }
    }
    right_side->parent = current->parent;
    current->parent = right_side;

    //Move the left subtree of right_side to the current's right
    current->right = right_side->left;
    if(current->right != nullptr) {
        current->right->parent = current;
    }

    //Move the current to the left of the right_side
    right_side->left = current;

    return true;
}

template<typename Type_T>
bool Red_Black_Tree<Type_T>::rotate_right(TreeNode<Type_T> *current) {
    if(current->left == nullptr) return false;
    TreeNode<Type_T>* left_side = current->left;

    //Setting the parent node
    if(current->parent == nullptr) {
        root = left_side;
    } else {
        if(current == current->parent->left) {
            current->parent->left = left_side;
        } else {
            current->parent->right = left_side;
        }
    }
    left_side->parent = current->parent;
    current->parent = left_side;

    //Move the right subtree of left_side to the current's left
    current->left = left_side->right;
    if(current->left != nullptr) {
        current->left->parent = current;
    }

    //Move the current to the right of the left_side
    left_side->right = current;

    return true;
}

template<typename Type_T>
void Red_Black_Tree<Type_T>::adjust_tree(TreeNode<Type_T> *current, TreeNode<Type_T> *child) {
    //Case 1: the root is red
    if(current == nullptr) {
        child->color = BLACK;
        return;
    }

    //Case 2: the parent tree is empty
    if(is_black(current)) {
        return;
    }

    TreeNode<Type_T>* grand_father = current->parent;
    TreeNode<Type_T>* uncle = grand_father->left == current ? grand_father->right : grand_father->left;

    if(!is_black(uncle)) {
        //Case 3: the uncle is red
        uncle->color = BLACK;
        current->color = BLACK;
        grand_father->color = RED;
        adjust_tree(grand_father->parent, current->parent);
        return;
    } else {
        //Case 4: the uncle is black
        if((uncle == grand_father->left && child == current->right) ||
                (uncle == grand_father->right && child == current->left)) {
            //Case 4.1: the uncle and the new node are in the different sides of their parents
            if(uncle == grand_father->left) rotate_left(grand_father);
            else rotate_right(grand_father);
            grand_father->flip();
            current->flip();
            return;
        } else {
            //Case 4.2: the uncle and the new node are in the same side of their parents
            if(child == current->left) rotate_right(current);
            else rotate_left(current);
            if(uncle == grand_father->left) rotate_left(grand_father);
            else rotate_right(grand_father);
            grand_father->flip();
            child->flip();
            return;
        }
    }
}

template<typename Type_T>
void Red_Black_Tree<Type_T>::adjust_tree(TreeNode<Type_T> *parent,
                                         TreeNode<Type_T> *child,
                                         TreeNode<Type_T> *brother) {
    /*
     *                     parent
     *                  /          \
     *               child        brother
     */

    //Case 1: parent is red while child, brother, and two children of brother are all black
    if(!is_black(parent) &&
       (brother == nullptr || (is_black(brother) && is_black(brother->left) && is_black(brother->right)))) {
        parent->flip();
        if(brother != nullptr) brother->flip();
        return;
    }

    //Case 2: parent, child, brother, and two children of brother are all black
    //Recursively modify the tree from low to high
    if(is_black(parent) &&
       (brother == nullptr || (is_black(brother) && is_black(brother->left) && is_black(brother->right)))) {
        if(brother != nullptr) brother->flip();
        TreeNode<Type_T>* new_parent = parent->parent;
        if(new_parent == nullptr) return; //Reach the root of the overall tree
        TreeNode<Type_T>* new_brother = new_parent->left == parent ? new_parent->right : new_parent->left;
        adjust_tree(new_parent, parent, new_brother);
        return;
    }

    //Case 3: brother is red
    //In this case, the brother must not be NULL
    if(!is_black(brother)) {
        if(child == parent->left) {
            rotate_left(parent);
        } else {
            rotate_right(parent);
        }
        brother->flip();
        parent->flip();
        TreeNode<Type_T>* new_brother = child == parent->left ? parent->right : parent->left;
        adjust_tree(parent, child, new_brother);
        return;
    }

    //Case 4: the child of brother on the same side of the child is red and the other one is black
    //The purpose of this case is to transform it into the case 5
    if((child == parent->left && !is_black(brother->left) && is_black(brother->right))
      ||(child == parent->right && !is_black(brother->right) && is_black(brother->left))) {
        if(child == parent->left) {
            brother->flip();
            brother->left->flip();
            rotate_right(brother);
            brother = parent->right;
        } else {
            brother->flip();
            brother->right->flip();
            rotate_left(brother);
            brother = parent->left;
        }
    }
    //Not return yet, need further handling

    //Case 5: the child of brother on the opposite side of the child is red
    //Note that the color of brother is guaranteed to be black.
    if((child == parent->left && !is_black(brother->right)) || (child == parent->right && !is_black(brother->left))) {
        TreeNode<Type_T>* adjust = child == parent->left ? brother->right : brother->left;
        brother->color = parent->color;
        parent->color = BLACK;
        adjust->color = BLACK;
        if(child == parent->left) rotate_left(parent);
        else rotate_right(parent);
        return;
    }
}

template<typename Type_T>
Red_Black_Tree<Type_T>::Red_Black_Tree() {
    root = nullptr;
    tree_size = 0;
}

template<typename Type_T>
Red_Black_Tree<Type_T>::Red_Black_Tree(const Red_Black_Tree<Type_T> &src) {
    copy_tree(root, nullptr, src.root);
    tree_size = src.tree_size;
}

template<typename Type_T>
Red_Black_Tree<Type_T>::~Red_Black_Tree() {
    empty();
}

template<typename Type_T>
Red_Black_Tree<Type_T> &Red_Black_Tree<Type_T>::operator=(const Red_Black_Tree<Type_T> &rhs) {
    if(this != &rhs) {
        empty();
        copy_tree(root, nullptr, rhs.root);
        tree_size = rhs.tree_size;
    }
    return *this;
}

template<typename Type_T>
bool Red_Black_Tree<Type_T>::is_empty() {
    return root == nullptr;
}

template<typename Type_T>
bool Red_Black_Tree<Type_T>::insert(Type_T key) {
    //Case 1: the tree is empty
    if(is_empty()) {
        root = new TreeNode<Type_T>(key, nullptr);
        ++ tree_size;
        return true;
    }

    //Find the location where the node should be added
    TreeNode<Type_T>* current = root;
    while(true) {
        if(current->data == key) {
            //The key has already existed
            return false;
        } else {
            if(key < current->data) {
                if(current->left == nullptr) break;
                current = current->left;
            } else {
                if(current->right == nullptr) break;
                current = current->right;
            }
        }
    }
    //At this point, current should be the parent of the new node

    TreeNode<Type_T>* child = new TreeNode<Type_T>(key, current, RED);
    if(key < current->data) current->left = child;
    else current->right = child;
    ++ tree_size;

    adjust_tree(current, child);

    return true;
}

template<typename Type_T>
bool Red_Black_Tree<Type_T>::remove(Type_T key) {
    TreeNode<Type_T>* current = search(key);

    //If the key doesn't exist, then directly return.
    if(current == nullptr) return false;

    //At this point, current is pointing to the node which needs to be removed.

    //Case 1: current has two sub trees
    //Replace data in the current by the smallest data in the current's right sub tree
    //Then current points to the smallest node which will then be removed
    if(current->left != nullptr && current->right != nullptr) {
        TreeNode<Type_T>* right_smallest = current->right;
        while(right_smallest->left != nullptr) {
            right_smallest = right_smallest->left;
        }
        current->data = right_smallest->data;
        current = right_smallest;
    }

    //Case 2: the node being removed is the root
    if(root == current) {
        root = current->left != nullptr ? current->left : current->right;
        if(root != nullptr) {
            root->parent = nullptr;
            root->color = BLACK;
        }
        clean_node(current);
        return true;
    }

    //At this point, the node being removed is guaranteed not to be the root
    //Replace the node by its child
    TreeNode<Type_T>* parent = current->parent;
    TreeNode<Type_T>* child = current->left != nullptr ? current->left : current->right;
    TreeNode<Type_T>* brother = current == parent->left ? parent->right : parent->left;
    if(child != nullptr) child->parent = parent;
    if(current == parent->left) parent->left = child;
    else parent->right = child;
    bool current_color = current->color;
    clean_node(current);

    //Case 3: the node removed is red
    if(current_color == RED) {
        //Remove the node has no effect to the overall structure.
        return true;
    }

    //Case 4: the node removed is black and the child is red
    if(!is_black(child)) {
        child->flip();
        return true;
    }

    //Rest cases: the node removed is black, and the child is also black
    //They will be handled in the ajust function
    adjust_tree(parent, child, brother);

    return true;
}

template<typename Type_T>
TreeNode<Type_T> *Red_Black_Tree<Type_T>::search(Type_T key) {
    TreeNode<Type_T>* result = root;
    while(result != nullptr && result->data != key) {
        if(key < result->data) result = result->left;
        else result = result->right;
    }
    return result;
}

template<typename Type_T>
unsigned int Red_Black_Tree<Type_T>::size() {
    return tree_size;
}

template<typename Type_T>
void Red_Black_Tree<Type_T>::print_tree() {
    if(root == nullptr) {
        std::cout << "The tree is empty" << std::endl << std::endl;
        return;
    }
    queue<TreeNode<Type_T>*> first;
    queue<TreeNode<Type_T>*> second;
    first.push_back(root);
    while(!first.is_empty() || !second.is_empty()) {
        if(!first.is_empty()) {
            while(!first.is_empty()) {
                auto temp = first.front();
                first.pop_front();
                if(temp != nullptr) {
                    std::cout << temp->data << "|";
                    if(temp->color) std::cout << "R|";
                    else std::cout << "B|";
                    second.push_back(temp->left);
                    second.push_back(temp->right);
                    if(temp->parent != nullptr) std::cout << temp->parent->data << "  ";
                }
            }
            std::cout << std::endl;
        } else {
            while(!second.is_empty()) {
                auto temp = second.front();
                second.pop_front();
                if(temp != nullptr) {
                    std::cout << temp->data << "|";
                    if(temp->color) std::cout << "R|";
                    else std::cout << "B|";
                    first.push_back(temp->left);
                    first.push_back(temp->right);
                    if(temp->parent != nullptr) std::cout << temp->parent->data << "  ";
                }
            }
            std::cout << std::endl;
        }
    }
    std::cout << "Size: " << tree_size << std::endl << std::endl;
}

template<typename Type_T>
void Red_Black_Tree<Type_T>::clean_node(TreeNode<Type_T> *current) {
    current->left = nullptr;
    current->right = nullptr;
    delete current;
    -- tree_size;
}

template<typename Type_T>
void Red_Black_Tree<Type_T>::copy_tree(TreeNode<Type_T> *&_root,
                                       TreeNode<Type_T> *parent,
                                       const TreeNode<Type_T> *src) {
    if(src == nullptr) return;
    _root = new TreeNode<Type_T>(src->data, parent, src->color);
    copy_tree(_root->left, _root, src->left);
    copy_tree(_root->right, _root, src->right);
}

template<typename Type_T>
void Red_Black_Tree<Type_T>::empty() {
    delete root;
    root = nullptr;
    tree_size = 0;
}

#endif //MY_STL_RED_BLACK_TREE_HPP
