#ifndef _GEN_UTIL_H_
#define _GEN_UTIL_H_
#include "pseudo_generator.hpp"

///////////////////////////////////////////
//Utility funtions
template<class generator, class unary_func, class binary_func>
typename unary_func::result_type map_reduce( pseudo_generator<typename generator::value_type, generator> &gen, const unary_func & f, const binary_func & reduce, typename binary_func::result_type init = 0 )
{
    typename unary_func::result_type val( init );
    for( typename generator::value_type x; gen( x ); ){//iterate over generated values...
	val = reduce( val, f( x ) );
    }
    return val;
}

/**Copy values from the generator to the inut iterator*/
template<class generator, class output_iter>
output_iter gen_copy(pseudo_generator<typename generator::value_type, generator> &g , output_iter itr)
{
    for(typename generator::value_type x; g >> x; ++itr){
	(*itr) = x;
    }
    return itr;
};

/**Copy values from the generator to the inut iterator, not more than specified*/
template<class generator, class output_iter>
output_iter gen_copy( pseudo_generator<typename generator::value_type, generator> &g, output_iter itr, output_iter itr_end)
{
    for(typename generator::value_type x; g( x ) && itr != itr_end; ++itr){
	(*itr) = x;
    }
    return itr;
};

#endif /* _GEN_UTIL_H_ */
