#ifndef TRAITS_HPP
#define TRAITS_HPP

#include <vector>
#include <iostream>

template <typename T>
class SS_Traits{
public:
    typedef T  value_t;
    typedef std::vector<value_t> container_t;
    typedef std::vector<value_t*> pcontainer_t;
    typedef typename container_t::iterator iterator_t;
  
    class simple_search{
    public:
        bool operator() (container_t a, value_t v){
            return false;
        }
    };

    class post_order_print{
    public:
        void operator() (void){
            std::cout << "post order" << std::endl;
        }
    };

    typedef simple_search functor_t;
    typedef post_order_print print_t;
};

template <typename T>
class BS_Traits{
public:
    typedef T  value_t;
    typedef std::vector<value_t> container_t;
    typedef std::vector<value_t*> pcontainer_t;
    typedef typename container_t::iterator iterator_t;
  
    class binary_search{
    public:
        bool operator() (container_t a, value_t v){
            return false;
        }
    };

    class pre_order_print{
    public:
        void operator() (void){
            std::cout << "pre order" << std::endl;
        }
    };
    typedef binary_search functor_t;
    typedef pre_order_print print_t;
};

#endif
