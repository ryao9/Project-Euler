#include <algorithm>
#include <vector>
#include <iostream>
#include "Euler.h"
using namespace std;

int formula_length(int a, int b, const vector<int> &primes) {
	int length = 0;
	while (binary_search(primes.begin(), primes.end(), length * length + a * length + b)) {
		++length;
	}
	return length;
}

int main() {
	vector<int> primes;
	primes_in_range(1000000, primes);
	int longest_length = 0;
	int product;

	for (int i = 0; primes[i] < 1000; ++i) {
		for (int j = -999; j < 1000; j += 1) {
			int current_length = formula_length(j, primes[i], primes);
			if (current_length > longest_length) {
				longest_length = current_length;
				product = j * primes[i];
			}
		}
	}
	cout << product;
}