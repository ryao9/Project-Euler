#include "Euler.h"
#include <vector>
using namespace std;

int sum_digit_factorial(int n) {
	vector<int> digits = digits_into_vector(n);
	int sum = 0;
	for (int i : digits) {
		sum += factorial(i);
	}
	return sum;
}

int main() {
	int sum = 0;
	for (int i = 3; i < 3000000; ++i) {
		if (i == sum_digit_factorial(i)) {
			sum += i;
		}
	}
	cout << sum;
}