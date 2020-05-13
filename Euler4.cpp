#include <iostream>
#include <cmath>
#include "Euler.h"
using namespace std;


int main()
{
	int max_palindrome = 0;
	for (int i = 100; i < 1000; ++i) {
		for (int j = 100; j < 1000; ++j) {
			if (is_palindrome(i * j) && i * j > max_palindrome) {
				max_palindrome = i * j;
			}
		}
	}
	cout << max_palindrome;
}
