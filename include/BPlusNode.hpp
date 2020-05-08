#ifndef BPLUSNODE_H
#define BPLUSNODE_H

#include <iostream>
#include <vector>
#include "Macros.hpp"
using namespace std;

// BPlusNode
template<typename T>
class BPlusNode {
public:
    typedef T value_t ;
    typedef vector<value_t> container_t;

    unsigned int order;
    container_t data;
    BPlusNode** children;
    BPlusNode* next;
    state_t state;
    size_t sizeOfContainer;

    BPlusNode(value_t data, unsigned int order = 4)
        : order(order),
          children(order,nullptr),
          data(order, 0),
          sizeOfContainer(0),
          state(state_t::NORMAL)
    {}

    void insert(int pos, const value_t& val) {
        int index;
        for(index=sizeOfContainer; index>pos; --index) {
            data[index] = data[index-1];
            children[index+1] =  children[index];
        }
        sizeOfContainer++;
        data[pos] = val;
        children[pos+1] =  children[pos];
    }

    ~BPlusNode(void){}
};


#endif
