#ifndef _GEN_ITERATOR_H_
#define _GEN_ITERATOR_H_
#include "pseudo_generator.hpp"
/****************************************************
 Helper templates
*/

template<class generator>
class gen_iterator: public std::iterator<std::input_iterator_tag, typename generator::value_type>
{
public:
    //Type definitions;
    typedef generator generator_type;
    typedef typename generator::value_type value_type;
private:
    //iterator state
    bool have_value;
    generator g;
    value_type cur_value;

public:
    //Create end() iterator
    gen_iterator(): have_value(false) {};
    //create begin() iterator
    explicit gen_iterator( const generator &g_ ):g(g_) { get_value(); };

    const value_type& operator*() const { return dereference(); };
    value_type& operator*() { return dereference(); };
    
    gen_iterator & operator ++(){ increment(); return *this; };

private:
    void get_value(){
	g >> cur_value;
	if ( !g ){ //generator reported stop, value is invalid
	    have_value = false;
	}else{
	    have_value = true;
	};
    };
    value_type & dereference(){
	if ( have_value )
	    return cur_value;
	else
	    throw std::logic_error("attempt to access end() iterator value");
    };
    const value_type & dereference()const{
	return const_cast< gen_iterator* >(this)->dereference();
    };
    void increment(){
	if ( !have_value ) throw std::logic_error( "attempt to increase end() iterator" );
	get_value();
    };

    template< class T >
    friend bool operator == ( const gen_iterator< T > & i1, const gen_iterator< T > & i2 );
};

template< class generator >
bool operator == ( const gen_iterator< generator > & i1, const gen_iterator< generator > & i2 )
{
    return 
	( &i1 == &i2 ) ||                   //each iterator is equal to itself  
	((!i1.have_value) && (!i2.have_value)); //and also, all end iterators are equal.
};

template< class generator >
bool operator != ( const gen_iterator< generator > & i1, const gen_iterator< generator > & i2 )
{
    return !( i1 == i2 );
};

#endif /* _GEN_ITERATOR_H_ */
