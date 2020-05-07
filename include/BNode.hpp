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

    void insertToContainer(value_t value){
        int index = sizeOfContainer - 1;

        while(index >= 0 && data[index] > value){
            data[++index] = data[index];
            index--;
        }

        data[++index] = value;
        sizeOfContainer++;
    }

    bool isContainerFull(){
        return sizeOfContainer == order;
    }

    void insert(value_t value, unsigned int order){
        // Si el children[0] es nullptr, es una leaf 
        if (!children[0]) {
            insertToContainer(value);
            return;
        }

        // Obtiene el hijo al que debe ir para insertar
        BNode* child = getNextChild(value);
        child->insert(value);

        if (child->isContainerFull()) {
            splitChild(child,order);
        }
    }

    BNode* getNextChild(value_t value){
        for(int i = 0; i < sizeOfContainer; i++){
            if (value <= data[i]) {
                return children[i];
            }
        }
        return children[sizeOfContainer];
    }

    //Terminar la insercion
    void splitChild(BNode* child, unsigned int order){
        BNode* newNode = new BNode(order);
        int m=(order/2)-1;
        int j=0;
        for(int i=m+1;i<order;i++){
            newNode->data[j]=this->data[i];
            newNode->sizeOfContainer++;
        }
    }

    ~BNode(void){}
};


#endif
