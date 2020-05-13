#include "Euler.h"
#include <iostream>
#include <vector>
using namespace std;

int chain_length(const vector<int> &v, int sum, int start) {
	int current_sum = 0;
	int length = 0;
	for (; current_sum < sum; ++length) {
		current_sum += v[start + length];
	}
	return (current_sum != sum) ? 0 : length;
}

int longest_chain(const vector<int> &v, int end) {
	int longest = 0;
	for (int i = 0; i < end; ++i) {
		int current_length = chain_length(v, v[end], i);
		if (current_length > longest) {
			longest = current_length;
		}
	}
	return longest;
}

int main() {
	vector<int> v;
	primes_in_range(1000000, v);
	int largest_chain = 0;
	for (size_t i = 0; i < v.size(); ++i) {
		int current_longest_chain = longest_chain(v, i);
		if (current_longest_chain > largest_chain) {
			largest_chain = current_longest_chain;
			cout << v[i] << endl;
		}
	}
}