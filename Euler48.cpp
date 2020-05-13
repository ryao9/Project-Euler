#include "Euler.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	vector<int> sum;
	for (int i = 1000; i > 0; --i) {
		v = digits_into_vector(i);
		exponentiate_digit_vectors(v, i);
		add_digit_vectors(sum, v);
	}
	for (int i = 9; i >= 0; --i) {
		cout << sum[i];
	}
}