#include "Euler.h"
#include <vector>
#include <iostream>
using namespace std;

void next_fibonacci(vector<int> &f_last, vector<int> &f_sec_last) {
	vector<int> f_last_copy = f_last;
	for (size_t i = 0; i < f_sec_last.size(); ++i) {
		f_last[i] += f_sec_last[i];
	}
	f_sec_last = f_last_copy;
	carry_over_digits(f_last);
}

int main() {
	vector<int> f_last = { 1 };
	vector<int> f_sec_last = { 1 };
	int index = 2;
	while (f_last.size() < 1000) {
		//print_vector_reverse(f_last);
		next_fibonacci(f_last, f_sec_last);
		++index;	
	}
	cout << index;
}