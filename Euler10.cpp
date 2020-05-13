#include <iostream>
#include <cmath>
using namespace std;

bool prime_test( double number ) 
{
   double max_check = pow( number , 0.5 );
   double index = 3;
   if ( fmod( number , 2 ) == 0 )
      return false;
   while ( index <= max_check )
   {
      if ( fmod( number , index ) == 0 )
         return false;
      index += 2;
   }
   return true;
}

int main()
{
   long total = 2;
   double prime = 3;
   while ( prime < 2000000 )
   {
      if ( prime_test( prime ) )
         total += prime;
      prime += 2;
   }
   cout << total;
}
