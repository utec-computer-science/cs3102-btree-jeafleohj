#ifndef BTREE_HPP
#define BTREE_HPP
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#include "types.hpp"
namespace tree {

template <typename T, std::size_t Order>
struct BTree {
    typedef typename T::value_t value_t;
    typedef typename T::container_t container_t;
    typedef typename T::functor_t functor_t;
private:
    struct Node {
        typedef typename T::value_t value_t;
        typedef typename T::container_t container_t;
        typedef typename T::iterator_t iterator_t;
        typedef std::vector<Node* > pcontainer_t;
        status_t status;
        container_t keys;
        pcontainer_t ptrs;
        int n_keys=0;
        Node() : keys(Order),
                 ptrs(Order, nullptr),
                 status(status_t::normal)
        {}
        void insert(int pos, const value_t& val) {
            int index;
            for(index=n_keys; index>pos; --index) {
                keys[index] = keys[index-1];
                ptrs[index+1] = ptrs[index];
            }
            n_keys++;
            keys[pos] = val;
            ptrs[pos+1] = ptrs[pos];
        }
    };
    Node *root;
    functor_t search;

public:

    BTree() : root(nullptr) {}

    ~BTree() {}

    bool empty() {return root==nullptr;}

    void split(Node* &parent, int pos, bool root=false) {
        Node* pnode = root ? this->root : parent->ptrs[pos];
        Node* left = new Node;
        Node* right = new Node;
        int mid = Order/2;
        value_t mid_value = pnode->keys[mid];

        std::move(std::begin(pnode->keys), std::begin(pnode->keys)+mid,
                  std::begin(left->keys));
        std::move(std::begin(pnode->ptrs), std::begin(pnode->ptrs)+mid+1,
                  std::begin(left->ptrs));

        std::move(std::begin(pnode->keys)+mid+1, std::end(pnode->keys),
                  std::begin(right->keys));

        std::move(std::begin(pnode->ptrs)+mid+1, std::end(pnode-> ptrs),
                  std::begin(right-> ptrs));

        left->n_keys = mid;
        right->n_keys = Order-mid-1;

        parent->insert(pos, mid_value);
        parent->ptrs[pos] = left;
        parent->ptrs[pos+1] = right;
        if(root) {
            this->root->n_keys = 1;
        }
    }

    status_t insert(Node* pnode, const value_t& val){
        container_t t=container_t(pnode->keys.begin(),
                                  pnode->keys.begin()+pnode->n_keys);
        int pos = search(t, val);
        if(pnode->ptrs[pos] != nullptr) {
            status_t current = insert(pnode->ptrs[pos], val);
            if(current == status_t::overflow) {
                split(pnode, pos);
            }
        } else {
            pnode->insert(pos, val);
        }
        if(pnode->n_keys == Order) {
            return status_t::overflow;
        }
        return status_t::normal;
    }

    void insert(const value_t &val = 0) {
        if(empty()) {
            root = new Node;
            root->keys[0] = val;
            root->n_keys = 1;
            return;
        }
        status_t current = insert(root,val);
        if(current == status_t::overflow) {
            int pos = 0;
            split(root,pos,true);
        }
    }
    bool find(Node* pnode, value_t value) {
        container_t t=container_t(pnode->keys.begin(),
                                  pnode->keys.begin()+pnode->n_keys);
        int pos = search(t, value);
        if(pnode->keys[pos] == value) return true;
        if(pnode->ptrs[pos]) {
            return find(pnode->ptrs[pos],value);
        }

        return false;
    }
    bool find(const value_t value = 0){
        return find(root, value);
    }

private:
    std::ostream& postorder(std::ostream &out, const Node *node) {
        if (node->ptrs[0]) {
            for (int i = 0; i <= node->n_keys; i++) {
                postorder(out, node->ptrs[i]);
            }
        }
        for (int i = 0; i < node->n_keys; i++) {
            out << node->keys[i] << ' ';
        }
        return out;
    }

    std::ostream& preorder(std::ostream &out, const Node *node) {
        for (int i = 0; i < node->n_keys; i++) {
            out << node->keys[i] << ' ';
        }
        if (node->ptrs[0]) {
            for (int i = 0; i <= node->n_keys; i++) {
                preorder(out, node->ptrs[i]);
            }
        }
        return out;
    }
public:
    friend  std::ostream &operator<<(std::ostream &out, BTree& tree) {
        if(type_print::postorder == T::tprint) {
            return tree.postorder(out, tree.root);
        } else if(type_print::preorder == T::tprint) {
            return tree.preorder(out, tree.root);
        }
        out<<"Inorder is not support";
        return out;
    }
};

}

#endif
