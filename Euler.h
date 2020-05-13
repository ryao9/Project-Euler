#ifndef EULER_H
#define EULER_H

#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>

int factorial(int n) {
	if (n == 0) {
		return 1;
	}

	for (int i = n - 1; i > 1; --i) {
		n *= i;
	}
	return n;
}

// Problem 21
// returns sum of proper divisors of n
int sum_divisors(int n) {
    int hold_n = n;
    int total = 1;
    for (int i = 2; i * i <= n; ++i) {
        int prime_sum = 1;
        while (n % i == 0) {
            prime_sum = prime_sum * i + 1;
            n /= i;
        }
        total *= prime_sum;
    }
    if (n > 1) {
        total *= 1 + n;
    }
    return total - hold_n;
}

// O(logn)
// Not working properly
int power(int n, int exp) {
	int result = 1;
	int exp_holder = exp;
	while (exp > 1) {
		result = n * n;
		exp /= 2;
	}
	if (exp_holder % 2 == 1) {
		result *= n;
	}
	return result;
}

bool is_palindrome(int n) {
	int n_reversed = 0;
	int digit = 1;
	while (n / digit != 0) {
		n_reversed *= 10;
		n_reversed += (n % (digit * 10)) / digit ;
		digit *= 10;
	}
	return n == n_reversed;
}

void primes_in_range(int max, std::vector<int> &primes) {
	std::vector<bool> factor_of_prime(max, false);
	for (int i = 2; i * i <= max; ++i) {
		if (!factor_of_prime[i - 1]) {
			for (int j = 2; i * j <= max; ++j) {
				factor_of_prime[i * j - 1] = true;
			}
		}
	}
	for (std::size_t i = 1; i < factor_of_prime.size(); ++i) {
		if (!factor_of_prime[i]) {
			primes.push_back(i + 1);
		}
	}
}

std::vector<int> digits_into_vector(int n) {
	std::vector<int> digits;
	int digit = 1;
	while (n / digit != 0) {
		digits.push_back((n % (digit * 10)) / digit);
		digit *= 10;
	}
	return digits;
}

void print_vector(const std::vector<int> &v, int space = 0, int columns = 4) {
	for (std::size_t i = 0; i < v.size(); ++i) {
		if (i % columns == 0) {
			std::cout << std::endl;
		}
		std::cout << std::setw(space) << v[i];
	}
	std::cout << std::endl;
}

void print_vector_reverse(const std::vector<int> &v, int space = 0, int columns = 4) {
	int print_count = 0;
	for (int i = v.size() - 1; i >= 0; --i) {
		if (print_count % columns == 0) {
			std::cout << std::endl;
		}
		std::cout << std::setw(space) << v[i];
		++print_count;
	}
	std::cout << std::endl;
}

void carry_over_digits(std::vector<int> &v) {
	for (std::size_t i = 0; i < v.size(); ++i) {
		if (v[i] >= 10) {
			int carry_over = v[i] / 10;
			v[i] = v[i] % 10;
			if (i < v.size() - 1) {
				v[i + 1] += carry_over;
			}
			else {
				v.push_back(carry_over);
			}
		}
	}
}

// Requires positive numbers
void add_digit_vectors(std::vector<int> &v1, std::vector<int> &v2) {
	for (int i = 0; i < v2.size(); ++i) {
		if (i >= v1.size()) {
			v1.push_back(0);
		}
		v1[i] += v2[i];
	}
	carry_over_digits(v1);
}

// Requires positive numbers
void multiply_digit_vectors(std::vector<int> &v1, std::vector<int> &v2) {
	std::vector<int> product;
	for (int i = 0; i < v2.size(); ++i) {
		for (int j = 0; j < v1.size(); ++j) {
			if (i + j + 1 > product.size()) {
				product.push_back(0);
			}
			product[i + j] += v2[i] * v1[j];
		}
	}
	carry_over_digits(product);
	v1 = product;
}

// Requires exponent > 0
void exponentiate_digit_vectors(std::vector<int> &v, int exponent) {
	std::vector<int> v_holder = v;
	for (int i = 1; i < exponent; ++i) {
		multiply_digit_vectors(v, v_holder);
	}
}

void factorial_digit_vector(std::vector<int> &v) {
	int converted_v = 0;
	int digit = 1;
	for (std::size_t i = 0; i < v.size(); ++i) {
		converted_v += v[i] * digit;
		digit *= 10;
	}

	for (int i = converted_v - 1; i > 1; --i) {
		std::vector<int> next_factorial_term = digits_into_vector(i);
		multiply_digit_vectors(v, next_factorial_term);
	}

	int sum = 0;
	for (std::size_t i = 0; i < v.size(); ++i) {
		sum += v[i];
	}
}

bool same_digits(int n1, int n2) {
	std::vector<int> v1 = digits_into_vector(n1);
	std::vector<int> v2 = digits_into_vector(n2);
	if (v1.size() == v2.size()) {
		std::vector<bool> digit_used(v1.size(), false);
		for (std::size_t i = 0; i < v1.size(); ++i) {
			bool contains_digit = false;
			for (std::size_t j = 0; j < v2.size(); ++j) {
				if (v1[i] == v2[j] && !digit_used[j]) {
					contains_digit = true;
					digit_used[j] = true;
					break;
				}
			}
			if (!contains_digit) {
				return false;
			}
		}
		return true;
	}
	return false;
}

#endif