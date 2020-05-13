#include <iostream>
#include <vector>
using namespace std;

int num_divisors(int n) {
	vector<int> primes;
	int index = 0;
	int n_holder = n;
	for (int i = 2; i * i <= n_holder; ++i) {
		if (n % i == 0) {
			primes.push_back(0);
			while (n % i == 0) {
				n /= i;
				++primes[index];
			}
			++index;
		}
	}
	
	if (n != 1) {
		return 2;
	}
	int result = 1;
	for (size_t i = 0; i < primes.size(); ++i) {
		result *= primes[i] + 1;
	}
	return result;
}

int main() {
	int triangle_num = 1;
	for (int i = 2; num_divisors(triangle_num) <= 500; ++i) {
		triangle_num += i;
	}
	cout << triangle_num;
}