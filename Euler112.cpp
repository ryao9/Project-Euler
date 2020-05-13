#include "Euler.h"
#include <iostream>
#include <vector>
using namespace std;


bool is_bouncy(int n) {
	vector<int>digits = digits_into_vector(n);
	bool is_increasing = true;
	bool is_decreasing = true;
	for (size_t i = 1; i < digits.size(); ++i) {
		if (digits[i] > digits[i - 1]) {
			is_decreasing = false;
		}
		else if (digits[i] < digits[i - 1]) {
			is_increasing = false;
		}
	}
	return !(is_increasing || is_decreasing);
}

int main() {
	int count = 0;
	int min = 1;
	do { 
		if (is_bouncy(min)) {
			++count;
			//cout << min << endl;
		}
		++min;
	} while ((count * 100) < 99 * (min - 1));
	cout << min - 1;
}