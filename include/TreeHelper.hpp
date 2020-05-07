#ifndef TREE_HELPER_H
#define TREE_HELPER_H

#include <iostream>
#include <stack>
#include "BNode.hpp"
#include "BPlusNode.hpp"
#include "BSTNode.hpp"
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
  
    static void  insert (node_t** head, const value_t& val, unsigned int order){
        cout << "Insertando para un nodo B" << endl;
        (*head)->insert(val,order);
    }

    static void  print (node_t** head, std::ostream &out){
    
    }
};

#endif
