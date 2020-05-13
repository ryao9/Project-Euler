#include "Euler.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	primes_in_range(10000, v);	
	for (size_t i = 0; i < v.size(); ++i) {
		for (size_t j = i + 1; j < v.size(); ++j) {
			if (binary_search(v.begin(), v.end(), v[j] + v[j] - v[i]) && same_digits(v[i], v[j]) && same_digits(v[i], v[j] + v[j] - v[i])) {
				cout << v[j] << "   " << v[i];
			}
		}
	}
	cout << same_digits(2969, 6299) << same_digits(2969, 9629);
}