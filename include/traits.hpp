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

    struct post_order_print {
        std::ostream& operator()(std::ostream& out) {
            out << "post order" << std::endl;
            return out;
        }
    };

    const static tree::type_print tprint = tree::type_print::postorder;
    typedef simple_search functor_t;
    typedef post_order_print print_t;
};

template <typename T>
class BS_Traits {
public:
    typedef T value_t;
    typedef std::vector<value_t> container_t;
    typedef typename container_t::iterator iterator_t;

    class binary_search {
    public:
      int operator()(container_t a, value_t v) { return 0; }
    };

    class pre_order_print {
    public:
      void operator()(void) { std::cout << "pre order" << std::endl; }
    };

    typedef binary_search functor_t;
    typedef pre_order_print print_t;
};

#endif
