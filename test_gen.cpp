#include "generator.hpp"
#include <iostream>
using namespace std;

struct gen1: public pseudo_generator<int, gen1> {
   int operator()();
   int x;
};

int gen1::operator()()
{
   BEGIN_GEN2( s1,s2 );
   for (x = 0; x<10; ++x){
      YIELD( x, s1 );
   }
   for( x = 1000; x< 1000+10; x+=2){
      YIELD( x,s2 );
   }
   END_GENERATOR;
   return -1;//dummy
};

int main(int argc, char *argv[])
{
   gen1 g;
   gen1::iterator i=g.begin(), e=g.end();
   
   for (; i!=e; ++i ){
      cout<< *i <<endl;
   }
   return 0;
}
