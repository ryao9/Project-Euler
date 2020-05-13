/*
Check each number one through 10000
  Check number isn't already in array of amicable numbers (not already added)
  If amicable, add pair to sum
  Add pair to array of amicable numbers
Check is amicable func
  Find sum of all divisors func
    get prime factorization
      while n > 1
        find first number, starting from 2, that divides n
          add this number to some container of prime factorization
          divide divident by this number
    Divisors are all possible combinations of powers in prime factorization
  Store sum and call sum of all divisors on sum
    if return is equal to amicable func argument, then amicable pair
      add amicable pair to container of amicable numbers
      return sum of pairs
    return 0
*/

#include <iostream>
#include "Euler.h"
using namespace std;

int amicable(int n) {
    int sum = sum_divisors(n);
    if (sum_divisors(sum) == n && sum != n) {
        return n;
    }
    return 0;
}

int main() {
    int sum = 0;
    for (int i = 2; i < 10000; ++i) {
        int add = amicable(i);
        sum += add;
        // cout << "adding " << add << " for i = " << i << endl;
    }
    cout << sum;
}


