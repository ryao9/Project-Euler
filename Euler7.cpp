#include <cmath>
#include <iostream>
using namespace std;

/*
bool fermat_test( double number )
{
   bool test_result = ( fmod( pow( 2 , number - 1 ) , number ) ) == 1;
   return test_result;
}
*/

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
   int prime_counter = 1;
   double number = 3;
   while ( prime_counter <= 10000 )
   { 
      if ( prime_test( number ) )
         prime_counter++;
      number += 2;
   }
   cout << number - 2;
}

