#include <iostream>
#include <set>
#include <cmath>
#include <vector>
using namespace std;

int power(int &n, int prime) {
	int power = 0;
	while (n % prime == 0) {
		n /= prime;
		++power;
	}
	return power;
}

bool repeat(int a, int b) {
	//find first prime and power
	//multiply power with b
	//find next smallest divisor of resulting product
	//if next smallest divisor and power are same, return false
	//if product divided by next smallest divisor is greater than 100 return true
	vector<int> prime_powers;

	for (int i = 2; a != 1; ++i) {
		if (a % i == 0) {
			prime_powers.push_back(power(a, i));
		}
	} 
	int smallest_power = prime_powers[0];
	for (size_t i = 1; i < prime_powers.size(); ++i) {
		if (prime_powers[i] < smallest_power) {
			smallest_power = prime_powers[i];
		}
	}

	int total_power = smallest_power * b;
	int next_smallest_power = smallest_power;
	for (int i = smallest_power - 1; i >= 1; --i) {
		if (total_power % i == 0) {
			next_smallest_power = i;
			break;
		}
	}

	if (next_smallest_power == smallest_power) {
		return false;
	}
	if (total_power / next_smallest_power <= 100) {
		cout << "Repeat with lowerst power " << smallest_power << " and exponent " << b << endl;
	}
	return total_power / next_smallest_power <= 100;
}

int main() {
	set<double> s;
	for (int a = 2; a <= 100; ++a) {
		for (int b = 2; b <= 100; ++b) {
			s.insert(pow(a, b));
		}
	}
	cout << s.size();
}