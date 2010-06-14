#pragma once
#ifndef _PSEUDO_GENERATOR_
#define _PSEUDO_GENERATOR_
#include <stdexcept>
////configuration
#define SAFE_PSEUDO_GENERATOR

/* This file is a header library, simplifying creation of the pseudo-generators,
   i.e., it imitates continuations. 
*/

template <class T>
class gen_iterator;

/**Base class for all pseudo_generators.*/
template<typename T, class child_generator>
struct pseudo_generator
{
    typedef T value_type;
    typedef gen_iterator< child_generator > iterator;

    int _continue_; //position of the reutrn point

    pseudo_generator(): _continue_(0){};
    bool stopped()const { return _continue_ == 1/*_end_state_*/; };
    //generator is true, when not stopped
    operator bool() const { return !stopped(); };

    iterator begin()const{ return iterator( static_cast< const child_generator &>(*this) ); };
    iterator end()const{ return iterator(); };
};

//Get the value of the generator and put it to the variable.
template< class T, class TC >
TC& operator >> ( pseudo_generator<T, TC> &g, T &v ){
    TC & generator = static_cast<TC &>(g);
    v = generator(); // operator() is defined for the descender, not for base
    return generator; // return the same generator to be able to chain calls
};

/* Macros, for simplified declaration of the generator classes
 */
#define BEGIN_GENERATOR_STATES  typedef enum{ _initial_state_=0, _end_state_=1,
#define END_GENERATOR_STATES    } _generator_state_type;

/* Implementation macros
 */

// Begins state restoration section. MUST be present at the beginning of the generator body, only once.
// THis macro may be followed by semicolon
#define BEGIN_RESTORE_STATE					\
    switch( static_cast< _generator_state_type >(_continue_) ){ 
		
// Restore particular code. State name must be one of the names, declared in the class.
// This macro MUST follow the BEGIN_RESTORE_STATE, and MUST be repeated for anu state used.
#define RESTORE_STATE(state_name)               \
    case state_name: goto _label_##state_name;
		
//Closes BEGIN_RESTORE_STATE. 
#define END_RESTORE_STATE                                               \
    case _initial_state_: goto _label__initial_state_;			\
    case _end_state_: throw std::logic_error("iterate after end");	\
    default: throw std::logic_error("Failed to restore state: state is unknown."); \
    }

/*Returns value and stores current state. "state" must be one of the states, declared in the header.
 */
#define YIELD(value, state)                     \
    _continue_ = state;				\
    return (value);				\
_label_##state:;

/*Declare beginning of the generator body. MUST follow the END_RESTORE_STATE.
 */
#define BEGIN_GENERATOR                         \
    _label__initial_state_:;

/*Closes the body*/
#define END_GENERATOR                           \
    _continue_ = _end_state_;			\
   

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

        
///////////////////////////////////////////
//Utility funtions
template<class generator, class unary_func, class binary_func>
typename unary_func::result_type map_reduce( generator& gen, const unary_func & f, const binary_func & reduce, typename binary_func::result_type init = 0)
{
    typename unary_func::result_type val( init );
    for( typename generator::value_type x; gen( x ); ){//iterate over generated values...
	val = reduce( val, f( x ) );
    }
    return val;
}

/**Copy values from the generator to the inut iterator*/
template<class generator, class output_iter>
output_iter gen_copy(generator & g, output_iter itr)
{
    for(typename generator::value_type x; g( x ); ++itr){
	(*itr) = x;
    }
    return itr;
};

/**Copy values from the generator to the inut iterator, not more than specified*/
template<class generator, class output_iter>
output_iter gen_copy(generator & g, output_iter itr, output_iter itr_end)
{
    for(typename generator::value_type x; g( x ) && itr != itr_end; ++itr){
	(*itr) = x;
    }
    return itr;
};

//convenience macros
#include "_generator.hpp"


#endif
