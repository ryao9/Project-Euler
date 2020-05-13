#include <vector>
#include <iostream>
#include "Euler.h"
using namespace std;

/*
Iterate from 10 to 999
Get digits for number store into vector
If size 3, add fixed amount based on hundreds digit
	recursive call with start iterator incremented
If size 2, 
	if 1 in tens digit call convert function
	else add fixed for both digits
*/

int letter_count(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1 || n == 2 || n == 6 || n == 10) {
		return 3;
	}
	if (n == 4 || n == 5 || n == 9) {
		return 4;
	}
	if (n == 3 || n == 7 || n == 8) {
		return 5;
	}
	if (n == 11 || n == 12 || n == 20) {
		return 6;
	}
	if (n == 15 || n == 16) {
		return 7;
	}
	if (n == 13 || n == 14 || n == 18 || n == 19) {
		return 8;
	}
	return 9;
}

int vector_letter_count(const vector<int> &digits) {
	int count = 0;
	
	if (digits.size() == 3) {
		count += letter_count(digits.back()) + 7;
		if (digits[0] || digits[1]) {
			count += 3;
		}
		if (digits[1] == 1 || !digits[1]) {
			count += letter_count(digits[1] * 10 + digits[0]);
		}
		//INCOMPLETE
	}

	return count;
}

int main() {
	int total = 0;

	for (int i = 1; i < 6; ++i) {
		total += letter_count(i);
	}


	cout << digits_into_vector(100).back();
}