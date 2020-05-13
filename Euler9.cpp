#include <cmath>
#include <iostream>

using namespace std;

int main()
{
   for (int i = 10; i < 800; i++)
   {
      for (int j = 10; j < 800; j++)
      {
         if ( (sqrt(pow(i, 2) + pow(j, 2) )) + i + j == 1000 )
            cout << (int)(sqrt(pow(i, 2) + pow(j, 2) )) * i * j << endl;
      }
   }
}
