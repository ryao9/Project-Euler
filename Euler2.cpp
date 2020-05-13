#include <iostream>
using namespace std;

int main()
{
   int fib1 = 1;
   int fib2 = 1;
   int sum = 0;
   int total = 0;

   while ( sum < 4000000 ) 
   {
      if (sum % 2 == 0)
         total += sum;

      sum = fib1 + fib2;
      fib1 = fib2;
      fib2 = sum; 
   }
 
   cout << total;      
           
}

