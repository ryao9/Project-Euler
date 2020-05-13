#include "Euler.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int sum = 0;
	for (int i = 10; i < 1000000; ++i) {
		vector<int> v = digits_into_vector(i);
		int digit_sum = 0;
		for (int i : v) {
			digit_sum += i * i * i * i * i;
		}
		if (digit_sum == i) {
			sum += i;
		}
	}
	cout << sum;
}