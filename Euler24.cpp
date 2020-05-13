#include <iostream>
#include <utility>
#include <vector>
#include "Euler.h"
using namespace std;

/*
Find nth lexicographic permutation of array of digits
Look at highest digit
  Find how many permutations there are where lowest number is at highest digit
  There are (array size - 1)! such permutations
  These are the first #permutations elements in the lexicographic permutation
  Repeat process with next smallest number
  Repeat until number of permutations exceeds n
  Whatever number ends at is the last digit
Repeat process til last digit
*/

pair<int, int> get_index(int permutations, int size) {
	int total_permutations = 0;
	int index = 0;
	int current_factorial = factorial(size - 1);
	while (total_permutations < permutations) {
		total_permutations += current_factorial;
		++index;
	}
	return pair<int, int>(index - 1, total_permutations - current_factorial);
}

int main() {
	vector<int> digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int nth_permutation[10];
	int permutations = 1000000;
	int size = 10;
	for (int i = 0; i < 10; ++i) {
		pair<int, int> index_and_permutations = get_index(permutations, size);
		nth_permutation[i] = digits[index_and_permutations.first];
		permutations -= index_and_permutations.second;
		digits.erase(digits.begin() + index_and_permutations.first);
		--size;
	}
	for (int i = 0; i < 10; ++i) {
		cout << nth_permutation[i] << "   ";
	}
}