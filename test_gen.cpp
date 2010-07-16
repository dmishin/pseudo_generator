#include "generator.hpp"
#include <iostream>
using namespace std;

struct gen1: public pseudo_generator<int, gen1> {
   void operator()( int& v );
   int x;
};

void gen1::operator()( int & v )
{
   GENERATOR2( s1,s2 );
   for (x = 0; x<10; ++x){
       YIELD( v, x, s1 );
   }
   for( x = 1000; x< 1000+10; x+=2){
       YIELD( v, x, s2 );
   }
   //   END_GENERATOR;
};

int main(int argc, char *argv[])
{
   gen1 g;
   for ( int i; g >> i; ){
      cout << i << endl;
   }
   return 0;
}
