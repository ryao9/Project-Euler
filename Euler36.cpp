#include "Euler.h"
#include <iostream>
#include <vector>
using namespace std;

bool is_binary_palindrome(int n) {
	vector<int> binary;
	while (n != 0) {
		binary.push_back(n % 2);
		n /= 2;
	}
	size_t size = binary.size();
	for (size_t i = 0; i < size / 2; ++i) {
		if (binary[i] != binary[size - i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	int sum = 0;
	for (int i = 1; i < 1000000; ++i) {
		if (is_binary_palindrome(i) && is_palindrome(i)) {
			sum += i;
		}
	}
	cout << sum;
}