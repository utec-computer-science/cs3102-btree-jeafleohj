#ifndef TRAITS_HPP
#define TRAITS_HPP
#include <ostream>
#include <vector>
#include <iostream>
#include "types.hpp"

template <typename T>
class SS_Traits {
public:
    typedef T value_t;
    typedef std::vector<value_t> container_t;
    typedef typename container_t::iterator iterator_t;
    struct simple_search {
        int operator()(container_t a, const value_t& v) {
            int pos;
            for(pos=0; pos<a.size()&& a[pos]<v; pos++);
            return pos;
        }
    };

    const static tree::type_print tprint = tree::type_print::postorder;
    typedef simple_search functor_t;
};

template <typename T>
class BS_Traits {
public:
    typedef T value_t;
    typedef std::vector<value_t> container_t;
    typedef typename container_t::iterator iterator_t;

    class binary_search {
    public:
        int operator()(container_t a, value_t v) {
            int low = 0;
            int high = a.size() - 1;
            while (low != high) {
                int mid = (low + high + 1)/2;
                if (a[mid] < v) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }
            return low + 1;
        }
    };

    typedef binary_search functor_t;
    const static tree::type_print tprint = tree::type_print::preorder;
};

#endif
