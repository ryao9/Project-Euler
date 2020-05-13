#include <iostream>
using namespace std;

int main()
{
   int sum3 = 3;
   int sum5 = 5;
   int sum3total = 0;
   int sum5total = 0;
   int sum15 = 15;
   int sum15total = 0;

   while ( sum3 < 1000 )
   {
      sum3total += sum3;
      sum3 += 3;
   }

   while ( sum5 < 1000 )
   {
      sum5total += sum5;
      sum5 += 5;
   }

   while ( sum15 < 1000 )
   {
      sum15total += sum15;
      sum15 += 15;
   }

   cout << sum3total + sum5total - sum15total;
}

