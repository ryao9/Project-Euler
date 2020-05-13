#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

double sequence_product(vector<double> &v, double end) {
	double product = 1;
	for (size_t i = 0; i < 13; ++i) {
		product *= v[end - i];
	}
	return product;
}

int main() {
	vector<double> large_num;
	std::ifstream fin;
	fin.open("Euler8.txt");

	if (fin.is_open()) {
		for (double i = 0; i < 1000; ++i) {
			char num[1];
			fin >> num[0];
			large_num.push_back(atoi(num));
		}
		fin.close();
	}

	double largest_product = sequence_product(large_num, 12);
	cout << largest_product << endl;
	for (size_t i = 13; i < large_num.size(); ++i) {
		double current_product = sequence_product(large_num, i);
		if (current_product > largest_product) {
			largest_product = current_product;
		}
	}
	cout << setprecision(20) << largest_product;
}
