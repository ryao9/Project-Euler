#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 15;

int set_triangle(int triangle[][SIZE]) {
	for (int r = 0; r < SIZE; ++r) {
		for (int c = 0; c < SIZE; ++c) {
			triangle[r][c] = 0;
		}
	}

	std::ifstream fin;
	fin.open("Euler18.txt");

	if (fin.is_open()) {
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < i + 1; ++j) {
				int num;
				fin >> num;
				triangle[i][j] = num;
			}
		}
		fin.close();
	}

	for (int i = SIZE - 2; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
		}
	}
}

int main() {
	int triangle[SIZE][SIZE];
	set_triangle(triangle);
	cout << triangle[0][0];
}