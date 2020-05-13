#include <iostream>
#include <vector>
#include "Euler.h"
using namespace std;

vector<int> digits_into_vector(int n) {
	vector<int> digits;
	int digit = 1;
	while (n / digit != 0) {
		digits.push_back((n % (digit * 10)) / digit);
		digit *= 10;
	}
	return digits;
}

int digits_into_integer(const vector<int> &digits) {
	int num = 0;
	int digit = 1;
	for (size_t i = 0; i < digits.size(); ++i) {
		num += digits[i] * digit;
		digit *= 10;
	}
	return num;
}

// Start at first digit
// Increment first digit and see if still prime
// Do 9 times, stop if not prime count passes 2, if not stop then is family
// 
// Some recursive function for finding identical digits

bool is_family(int n) {
	vector<int> digits = digits_into_vector(n);
	for (size_t i = 0; i < digits.size(); ++i) {
		vector<int> holder_digits = digits;
		for (size_t j = 0; j < digits.size(); ++j) {
			
		}
	}
}

int main() {
	vector<int> primes = { 2 };
	primes_up_to_limit(10000000, primes);
}