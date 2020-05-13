#include <vector>
#include "Euler.h"
#include <iostream>
using namespace std;

/*
Ways to make n dollars
Number of ways using largest coin
Number of ways without using largest coin
*/

int num_ways_to_make_value(int value, vector<int> coins) {
	if (value == 0) { return 1; }
	else if (value < 0) { return 0; }
	else if (coins.size() == 1) { return 1; } 
	vector<int> minus_largest_coin = coins;
	minus_largest_coin.pop_back();
	return num_ways_to_make_value(value - coins[coins.size() - 1], coins) + num_ways_to_make_value(value, minus_largest_coin);
}

int main() {
	int arr_coins[] = { 1, 2, 5, 10, 20, 50, 100, 200 };
	vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 200 };
	//cout << num_ways_to_make_value(200, coins);
	cout << power(3, 2) << power(3, 3) << pow(3, 1) << pow(3, 4) << pow(3, 5);
}