//
// Created by Pleiades Lin on 2020-08-19.
//

#ifndef MY_STL_RED_BLACK_TREE_H
#define MY_STL_RED_BLACK_TREE_H

#define BLACK false
#define RED true

template<typename Type_T>
struct TreeNode {

    //Data stored, and by default it is the key.
    Type_T data;

    //Color of the node, which can only be red or black.
    bool color;

    //Pointers of children and parent.
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    //Default constructor: the color by default is black.
    TreeNode(Type_T _data, TreeNode* _parent): data(_data), parent(_parent) {
        color = false;
        left = nullptr;
        right = nullptr;
    }

    //Constructor with given data, parent, and color.
    TreeNode(Type_T _data, TreeNode* _parent, bool _color): data(_data), parent(_parent), color(_color) {
        left = nullptr;
        right = nullptr;
    }

    //Helper function: flip the color of the node.
    void flip() {color = !color;};

    //Destructor: it cleans the entire tree.
    ~TreeNode() {
        delete left;
        left = nullptr;
        delete right;
        right = nullptr;
    };
};

template<typename Type_T>
class Red_Black_Tree {
private:

    //The root of the tree.
    TreeNode<Type_T>* root;

    //The size of the tree.
    unsigned int tree_size;

    //Copy the tree node
    void copy_tree(TreeNode<Type_T>*& root, TreeNode<Type_T>* parent, const TreeNode<Type_T>* src);

    //Return true if the current node is black (Helper function).
    bool is_black(TreeNode<Type_T>* current);

    //Left tree rotate (Helper function).
    bool rotate_left(TreeNode<Type_T>* current);

    //Right tree rotate (Helper function).
    bool rotate_right(TreeNode<Type_T>* current);

    //Delete a single node
    void clean_node(TreeNode<Type_T>* current);

    //Adjust the tree by using rotations:
    void adjust_tree(TreeNode<Type_T>* current, TreeNode<Type_T> *child);
    void adjust_tree(TreeNode<Type_T>* parent, TreeNode<Type_T> *child, TreeNode<Type_T> *brother);

public:

    //Default constructor.
    Red_Black_Tree();

    //Copy constructor.
    Red_Black_Tree(const Red_Black_Tree<Type_T>& src);

    //Destructor.
    ~Red_Black_Tree();

    //"=" operator overloading.
    Red_Black_Tree<Type_T>& operator=(const Red_Black_Tree<Type_T>& rhs);

    //Return true if the tree is empty.
    bool is_empty();

    //Insert a new key. Return true if success.
    bool insert(Type_T key);

    //Remove an existing key. Return true if success.
    bool remove(Type_T key);

    //Search a given key. Return the node if found, otherwise return NULL.
    TreeNode<Type_T>* search(Type_T key);

    //Return the size of the tree
    unsigned int size();

    //Print the tree.
    void print_tree();

    //Empty the tree
    void empty();
};

#endif //MY_STL_RED_BLACK_TREE_H
