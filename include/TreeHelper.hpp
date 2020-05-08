#ifndef TREE_HELPER_H
#define TREE_HELPER_H

#include <iostream>
#include <stack>
#include "BNode.hpp"
#include "BPlusNode.hpp"
#include "BSTNode.hpp"
#include "Macros.hpp"
using namespace std;

template<typename  Node, typename  ValueNode, int Flag>
struct TreeHelper{
    typedef Node  node_t;
    typedef typename node_t::value_t value_t;

    static void  insert (node_t** head, const value_t& val, unsigned int order){
        cout << "el tipo de dato no es compatible" << endl;
    }

    static void  print (node_t** head, std::ostream &out){
    }
};


template<typename  ValueNode>
struct TreeHelper<BSTNode<ValueNode>,ValueNode,BST_NODE_FLAGXX>{
    typedef BSTNode<ValueNode>  node_t;
    typedef typename node_t::value_t value_t;
  
    static void  insert (node_t** head, const value_t& val, unsigned int order){
        auto temp = new node_t(val);
    
        if ((*head)== nullptr) {
            (*head) = temp;     
            return;
        }
    
        if ((*head)->data > val){
            insert(&(*head)->children[0], val, order);
            return;
        }

        if ((*head)->data < val){
            insert(&(*head)->children[1], val, order);
            return;
        }
        cout << "Duplicates not allowed" << endl;
    }

    //BST Print
    static void  print (node_t** head, std::ostream &out){
        std::stack<node_t*> nodes;
        node_t *curr = *head;
    
        while(curr) {
            out << "Node: " << curr->data << endl;
            if (curr->children[1]) {
                nodes.push(curr->children[1]);
            }
            if (curr->children[0]) {
                curr = curr->children[0];
            } else {
                if (!nodes.empty()) {
                    curr = nodes.top(); 
                    nodes.pop();
                } else {
                    curr = nullptr;
                }
            } 
        }
    }
};

template<typename ValueNode>
struct TreeHelper<BNode<ValueNode>,ValueNode,B_NODE_FLAGXX>{
    typedef BNode<ValueNode>  node_t;
    typedef typename node_t::value_t value_t;
  
    static state_t insert(node_t** ppnode, const value_t& val) {
        unsigned int pos=0;
        while(pos<(*ppnode)->sizeOfContainer && (*ppnode)->data[pos]<val) {
            pos++;
        }

        if((*ppnode)->children[pos]) {
            state_t cstate = insert(ppnode, val);
            if( cstate == state_t::OVERFLOW ) {
                split(ppnode, pos);
            } else {
                (*ppnode)->insertInNode(val, pos);
            }
        }
        return (*ppnode)->state();
    }

    static void split(node_t** ppnode, int pos, bool root=false) {
        unsigned int order = (*ppnode)->order;
        unsigned int mid = order>>1;
        node_t* focus = root ? (*ppnode) : (*ppnode)->children[pos];
        node_t* left = new node_t(order);
        node_t* right = new node_t(order);
        value_t mid_value = focus->data[mid];

        std::move(std::begin(focus->data),
                  std::begin(focus->data)+mid,
                  std::begin(left->data));
        std::move(std::begin(focus->children),
                  std::begin(focus->children)+mid+1,
                  std::begin(left->children));

        std::move(std::begin(focus->data)+mid+1,
                  std::end(focus->data),
                  std::begin(right->data));

        std::move(std::begin(focus->children)+mid+1,
                  std::end(focus-> children),
                  std::begin(right-> children));

        left->sizeOfContainer = mid;
        right->sizeOfContainer = order-mid-1;

        (*ppnode)->insert(pos, mid_value);
        (*ppnode)->children[pos] = left;
        (*ppnode)->children[pos+1] = right;

        if(root) {
            focus->sizeOfContainer = 1;
        }
    }

    static void  insert (node_t** head, const value_t& val, unsigned int order){
        if (*head == nullptr) {
            *head = new node_t(order);
            (*head) -> data[0] = val;
            (*head) -> sizeOfContainer = 1;
            return;
        }
        state_t state = insert(head, val);
        if( state == state_t::OVERFLOW ) {
            split(head, 0,true);
        }
    }

    static void  print (node_t** head, std::ostream &out){
        if ((*head)->children[0]) {
            for (int i = 0; i <= (*head)->sizeOfContainer; i++) {
                print( &((*head)->children[i]), out);
            }
        }
        for (int i = 0; i < (*head)->sizeOfContainer; i++) {
            out << (*head)->data[i] << ' ';
        }
    }
};

#endif
