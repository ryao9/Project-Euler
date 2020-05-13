#include "Euler.h"
#include <vector>
using namespace std;

bool reversible(int n) {
	vector<int> digits = digits_into_vector(n);
	vector<int> reverse;
	for (int i = digits.size() - 1; i >= 0; --i) {
		reverse.push_back(digits[i]);
	}
	add_digit_vectors(digits, reverse);
	for (size_t i = 0; i < digits.size(); ++i) {
		if (digits[i] % 2 == 0) {
			return false;
		}
	}
	return true;
}

int digits(int n) {
	int digit = 1;
	while (n >= 10) {
		n /= 10;
		digit *= 10;
	}
	return digit;
}

int main() {
	int count = 0;
	int digit = 1;
	int digit_tracker;
	bool d[1000000000];
	/*for (int i = 1; i < 1000000000; ++i) {
		if ((i / digits(i) + i % 10) % 2 == 0);
		else {
			if (reversible(i)) {
				++count;
			}
		}	
	}*/
	cout << count;
}