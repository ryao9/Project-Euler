#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int horizontal(const int arr[][20], int row, int column) {
    return arr[row][column] * arr[row][column + 1] 
           * arr[row][column + 2] * arr[row][column + 3];
} 

int vertical(const int arr[][20], int row, int column) {
    return arr[row][column] *  arr[row + 1][column]
           * arr[row + 2][column] * arr[row + 3][column];
}

int right_diagonal(const int arr[][20], int row, int column) {
     return arr[row][column] *  arr[row + 1][column + 1] 
            * arr[row + 2][column + 2] *  arr[row + 3][column + 3];
}

int max(int num1, int num2, int num3) {
    if (num1 >= num2) {
        return (num1 >= num3 ? num1 : num3);
    }
    return (num2 >= num3 ? num2 : num3);
}

int largest_product_at_r_c(const int arr[][20], int row, int column) {
    int horizontal_product = 0;
    int vertical_product = 0;
    int right_diagonal_product = 0;
    int left_diagonal_product = 0;

    if (column <= 16) {
        horizontal_product = horizontal(arr, row, column);
    }
    if (row <= 16) {
        vertical_product = vertical(arr, row, column);
    }
    if (row <= 16 && column <= 16) {
        right_diagonal_product = right_diagonal(arr, row, column);
    }

    return max(horizontal_product, vertical_product, right_diagonal_product);
}

int main() {
    ifstream series;
    series.open("Euler11.txt");
    int arr[20][20];

    for (int r = 0; r < 20; ++r) {
        for (int c = 0; c < 20; ++c) {
            series >> arr[r][c];
        }
    }

    int greatest_product = 0;
    for (int r = 0; r < 20; ++r) {
        for (int c = 0; c < 20; ++c) {
            int greatest_product_at_r_c = largest_product_at_r_c(arr, r, c);
            if (c % 5 == 0) {cout << endl;}
            cout << greatest_product_at_r_c << " at row " << r << " column " << c << " ";
            if (greatest_product_at_r_c > greatest_product) {
                greatest_product = greatest_product_at_r_c;
            }
        }
    }

    cout << greatest_product;
}