#include <iostream>
using namespace std;

// too slow
int lattice_path(int x, int y, int size) {
	if (y > size || x > size) {
		return 0;
	}
	else if (x == size && y == size) {
		return 1;
	}
	return lattice_path(x + 1, y, size) + lattice_path(x, y + 1, size);
}

int main() {
	cout << lattice_path(0, 0, 20);
}