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
    typedef SS_Traits<string> sstrait_t;
    BTree<strait_t, 4> stree;
    BTree<btrait_t, 4> btree;
    BTree<sstrait_t, 4> sstree;

    cout << "Testing ss" << "\n";
    stree.insert(10);
    stree.insert(20);
    stree.insert(80);
    stree.insert(19);
    stree.insert(30);
    stree.insert(-10);
    stree.insert(1);
    stree.insert(5);
    stree.insert(7);
    cout<<stree<<endl;
    cout << stree.find(5) << "\n";
    cout << stree.find(70) << "\n";
    cout << stree.find(-10) << "\n";
    cout << stree.find(100) << "\n";

    cout << "testing bs" << "\n";

    btree.insert(10);
    btree.insert(20);
    btree.insert(80);
    btree.insert(19);
    btree.insert(30);
    btree.insert(-10);
    btree.insert(1);
    btree.insert(5);
    btree.insert(7);
    cout<<btree<<endl;
    cout << btree.find(5) << "\n";
    cout << btree.find(70) << "\n";
    cout << btree.find(-10) << "\n";
    cout << btree.find(100) << "\n";
}
