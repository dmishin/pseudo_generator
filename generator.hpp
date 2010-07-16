#pragma once
#ifndef _PSEUDO_GENERATOR_
#define _PSEUDO_GENERATOR_
#include <stdexcept>
#define SAFE_PSEUDO_GENERATOR

/* This file is a header library, simplifying creation of the pseudo-generators,
   i.e., it imitates continuations. 
*/

template <class T>
class gen_iterator;

/**Base class for all pseudo_generators.
 * uses "Curiously Recurring Template Pattern"
 */
template<typename T, class child_generator>
struct pseudo_generator
{
    typedef T value_type;
    int _continue_; //position of the reutrn point

    pseudo_generator(): _continue_(0){};
    bool stopped()const { return _continue_ == 1/*_end_state_*/; };
    
    //generator is true, when not stopped
    operator bool() const { return !stopped(); };
};

//Get the value of the generator and put it to the variable. Same generator is returned
template< class T, class TC >
TC& operator >> ( pseudo_generator<T, TC> &g, T &v ){
    TC & generator = static_cast<TC &>(g);
    generator( v );
    return generator; // return the same generator to be able to chain calls
};


/**********************************************************************************
/* Internal implementation macros, for simplified declaration of the generator classes
**********************************************************************************/
#define _BEGIN_GENERATOR_STATES  typedef enum{ _impossible_state_ = -1, _initial_state_ = 0, _end_state_ = 1,
#define _END_GENERATOR_STATES    } _generator_state_type;

/* Implementation macros */

// Begins state restoration section. MUST be present at the beginning of the generator body, only once.
// This macro may be followed by semicolon
#define _BEGIN_RESTORE_STATE \
    switch( static_cast< _generator_state_type >(_continue_) ){ 
		
// Restore particular code. State name must be one of the names, declared in the class.
// This macro MUST follow the BEGIN_RESTORE_STATE, and MUST be repeated for anu state used.
#define _RESTORE_STATE(state_name)               \
    case state_name: goto _label_##state_name;
		
//Closes BEGIN_RESTORE_STATE. 
#define _END_RESTORE_STATE                                              \
    case _initial_state_: goto _label__initial_state_;			\
    case _end_state_: throw std::logic_error("iterate after end");	\
    case _impossible_state_: goto _label__impossible_state_;            \ 
    default: throw std::logic_error("Failed to restore state: state is unknown."); \
    }


/*Returns value and stores current state. "state" must be one of the states, declared in the header. */
#define YIELD(variable, value, state)		\
    {_continue_ = state;			\
    (variable) = (value);                       \
    return;				        \
    _label_##state:;}

/*Declare beginning of the generator body. MUST follow the END_RESTORE_STATE. */
#define _BEGIN_GENERATOR _label__initial_state_:;

/*Closes the body*/
//label is added here with the only purpose: to prevent successful complation in the situations,
//when programmer forgot to put END_GENERATOR. It is essential for the successful working of the code.
#define END_GENERATOR _label__impossible_state_: _continue_ = _end_state_; 
   


//convenience macros
#include "_generator.hpp"


#endif
