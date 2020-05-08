/*
 * file: main.cpp
 * author: Jhony Angulo
 * date: 16-04-2020
 */

#include <iostream>
#include <vector>
#include <stack>
#include <time.h>
#include <chrono>
#include <stdio.h>
#include <unistd.h>

#include "Tree.hpp"

int main() {
    typedef BSTNode<float> bst_node;
    typedef BNode<int> b_node;
    typedef Tree<b_node> b_tree;

    b_tree tree(4);
    tree.insert(30);
    tree.insert(10);
    tree.insert(60);

    cout << tree << endl;
}
