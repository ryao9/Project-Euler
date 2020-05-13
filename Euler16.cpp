//multiply first digit
//if product over 9, product % 10
//add 1 to next digit

#include <vector>
#include <iostream>
#include "Euler.h"
using namespace std;

void power_digits(vector<int> &base) {
	for (size_t i = 0; i < base.size(); ++i) {
		base[i] *= 2;
	}
	carry_over_digits(base);
}

int main() {
	vector<int> v = { 1 };
	for (int i = 0; i < 1000; ++i) {
		power_digits(v);
	}
	int sum = 0;
	for (size_t i = 0; i < v.size(); ++i) {
		sum += v[i];
	}
	cout << sum;
}