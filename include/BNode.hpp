#ifndef BNODE_H
#define BNODE_H

#include <iostream>
#include <vector>
#include "Macros.hpp"
using namespace std;

template<typename T>
class BNode {
public: 
    typedef T value_t ;
    typedef vector<value_t> container_t;
    typedef vector<BNode*> pcontainer_t;

    unsigned int order;
    container_t data;
    pcontainer_t children;
    size_t sizeOfContainer;

    BNode( unsigned int order = 4)
        : order(order),
          children(order,nullptr),
          data(order, 0),
          sizeOfContainer(0)
    {}

    state_t state() {
        if( sizeOfContainer == order ) {
            return state_t::OVERFLOW;
        }
        return state_t::NORMAL;
    }

    void insertInNode(const value_t& val, int pos) {
        int index;
        for(index=sizeOfContainer; index>pos; --index) {
            data[index] = data[index-1];
            children[index+1] =  children[index];
        }
        sizeOfContainer++;
        data[pos] = val;
        children[pos+1] =  children[pos];
    }

    ~BNode(void){}
};


#endif
