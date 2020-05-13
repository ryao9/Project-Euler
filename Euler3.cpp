#include <iostream>
#include <math.h>

using namespace std;

/* (FAILED) ATTEMPT 1

bool checkPrime( long number )
{
   long divisor = sqrt(number);
   
   while (divisor > 1)
   {
      if ( number % divisor == 0 )
         return false;
      divisor -= 1;
   }
   
   return true;      
}

long largestPrime( long number )
{
   long prime_checker = number/2; 
   bool not_prime = true;

   if ( checkPrime(number) )
      return number;
   
   while ( not_prime )
   {
      if ( number % prime_checker == 0 and checkPrime( prime_checker ) )
            not_prime = false;
      else
         prime_checker -= 1;
   }

   return prime_checker;
}

int main()
{
   long test_number;
   
   cout << "What number do you want to find the largest prime divisor of?\n";
   cin >> test_number;
   cout << "The largest prime divisor of " << test_number << " is " 
        << largestPrime( test_number ) << endl;
}

*/

// Attempt 2: Find smallest divisor (guaranteed to be prime) and divide number by this divisor. Repeat for resulting quotient until quotient = 1. Compare all divisors for largest divisor (would be easy with arrays if knew how...)

int main()
{
   long test_number; 
   long largest_prime = 0;

   cout << "What number do you want to find the largest prime divisor of?\n";
   cin >> test_number;

   long test_quotient = test_number;
   
   while ( test_quotient != 1)
   {
      long divisor_index = 2;

      while ( test_quotient % divisor_index != 0 )
      {   
         divisor_index += 1;
      }
      
      test_quotient = test_quotient / divisor_index; 

      if ( divisor_index > largest_prime )
         largest_prime = divisor_index; 
          
   }

   cout << largest_prime << endl;
}

