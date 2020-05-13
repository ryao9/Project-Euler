#include <iostream>
#include <vector>
#include "Euler.h"
using namespace std;

bool is_abundant(int n) {
    return sum_divisors(n) > n;
}

void populate_abundant_numbers(int max, vector<int> &abundant_numbers) {
    for (int i = 1; i <= max; ++i) {
        if (is_abundant(i)) {abundant_numbers.push_back(i);}
    }
}

bool is_sum_of_abundant_numbers(int n, const vector<int> &abundant_numbers) {
    /* start from first and last of abundant numbers
       if sum > n momve last left else if sum < n move first right
       else equal return true
       repeat until last not greater than first */
    int first = 0;
    int second = abundant_numbers.size() - 1;
    while (second >= first) {
       // cout << "first: " << abundant_numbers[first] << " second: " << abundant_numbers[second]; 
        int sum = abundant_numbers[first] + abundant_numbers[second];
        if (sum > n) {--second;}
        else if (sum < n) {++first;}
        else {return true;}
    }
    return false;
}

int main() {
    vector<int> abundant_numbers;
    int sum = 0;
    populate_abundant_numbers(28123, abundant_numbers);
    for (int i = 1; i <= 28123; ++i) {
        if (!is_sum_of_abundant_numbers(i, abundant_numbers)) {
            sum += i;
            cout << "adding " << i << endl;
        }
    }
    cout << sum;
}