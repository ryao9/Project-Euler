#include <iostream>
using namespace std;

int main() {
	int sum = 1;
	int add = 1;
	int add_diff = 2;
	for (int i = 0; i < 500; ++i) {
		for (int j = 0; j < 4; ++j) {
			add += add_diff;
			sum += add;
		}
		add_diff += 2;
	}

	cout << sum;
}