/*
 * file: main.cpp
 * author: Jhony Angulo
 * date: 16-04-2020
 */
#include "types.hpp"
#include "traits.hpp"
#include "btree.hpp"
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <ostream>
#include <tuple>
#include <vector>
#include <string>

using namespace std;
using namespace tree;

int main() {
    typedef BS_Traits<int> btrait_t;
    typedef SS_Traits<float> strait_t;
    BTree<btrait_t, 4> tree;
    //BTree<strait_t, 4> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(80);
    tree.insert(19);
    tree.insert(30);
    tree.insert(-10);
    tree.insert(1);
    tree.insert(5);
    tree.insert(7);
    cout<<tree<<endl;
    cout<<tree<<endl;
    //cout << tree.find(5) << "\n";
    // BTree<btrait_t,10> stree;
    // std::cout<<stree<< std::endl;
}
