#include <iostream>
#include <cmath>
using namespace std;

double sequence( double number ) {
   double counter = 1;
   while (number != 1 ) {
	  if (fmod(number, 2) == 0) {
		  number = number / 2;
	  }     
	  else {
		  number = 3 * number + 1;
	  }        
      counter++;
   }
   return counter;
}

int main()
{
	double highest_chain = 0;
	double highest_number = 0;
	for (double i = 1; i < 1000000; ++i) {
		double current_chain = sequence(i);
		if (current_chain > highest_chain) {
			highest_chain = current_chain;
			highest_number = i;
		}
	}
   cout << highest_number;
}
