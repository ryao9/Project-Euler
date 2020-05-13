#include "Euler.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	vector<vector<int>> large_nums;
	std::ifstream fin;
	fin.open("Euler13.txt");

	if (fin.is_open()) {
		for (int j = 0; j < 100; ++j) {
			vector<int> large_num;
			for (int i = 0; i < 50; ++i) {
				char num[1];
				fin >> num[0];
				large_num.push_back(atoi(num));
			}
			large_nums.push_back(large_num);
		}
		fin.close();
	}

	for (size_t i = 1; i < 1; ++i) {
		add_digit_vectors(large_nums[0], large_nums[i]);
	}
	int result = 0;
	int digit = 1;
	for (size_t i = 0; i < 10; ++i) {
		result += large_nums[0][i] * digit;
		digit *= 10;
	}

	cout << result;
}

