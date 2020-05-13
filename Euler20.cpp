#include "Euler.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<int> v = digits_into_vector(100);
	factorial_digit_vector(v);
	int sum = 0;
	for (std::size_t i = 0; i < v.size(); ++i) {
		sum += v[i];
	}
	cout << sum;
}