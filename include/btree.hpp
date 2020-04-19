#ifndef BTREE_HPP
#define BTREE_HPP

#include <iostream>
#include <vector> 

template <typename T, int S> 
class BNode {
public:
    typedef typename T::value_t value_t;
    typedef typename T::container_t container_t;
    typedef typename T::pcontainer_t pcontainer_t;

    container_t keys;
    pcontainer_t ptrs;
    std::size_t  order;

    BNode(void):order(S){
        keys=container_t(order,0);
        ptrs=pcontainer_t(order,NULL);
    }

    ~BNode(void){}
};

template <typename T, int S>
class BTree {
public: 
    typedef typename T::value_t value_t;
    typedef typename T::functor_t functor_t;
    typedef typename T::print_t print_t;

    BNode<T,S>* root;
    print_t print;
    functor_t search;

    BTree(void):root(NULL){
    }

    ~BTree(void){}

    void insert(const value_t& val = 0){
        // TODO :: INSERT
    }

    bool find(const value_t = 0) const{
        // TODO :: SEARCH
        // search(x); inside each page
        return false;
    }

    template <typename _T, int _S>
    friend std::ostream& operator<<(std::ostream& out, BTree<_T,_S> tree){
        tree.print();// (out)
        // IN PRE POST LEVEL ORDER
        return out;
    }

};


#endif
