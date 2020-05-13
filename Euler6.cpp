#include <iostream>
#include <cmath>
using namespace std;

unsigned long square_sum( unsigned long max )
{
   unsigned long sum = 0;
   for ( unsigned long i = 1; i <= max; i++ )
   {
      sum += i;
   } 
   return sum * sum;
}

unsigned long sum_square( unsigned long max )
{
   unsigned long sum = 0;
   for ( unsigned long i = 1; i <= max; i++ )
   {
      sum += ( i * i );
   }    
   return sum;
}

int main()
{
   unsigned long diff = 0;
   diff = square_sum( 100 ) - sum_square( 100 );
   cout << diff;
}
