/*
 * file: main.cpp
 * author: Jhony Angulo
 * date: 16-04-2020
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "btree.hpp"
#include "traits.hpp"
using namespace std;


int main() {
    typedef BS_Traits<int> btrait_t;
    typedef SS_Traits<float> strait_t;
    BTree<btrait_t,4> tree;
    tree.find(10);
    std::cout<<tree<< std::endl;
    //BTree<btrait_t,10> stree; 
    //std::cout<<stree<< std::endl;
}
