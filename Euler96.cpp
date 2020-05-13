#include <set>
#include "Sudoku.h"
#include <vector>
#include <utility>
#include <string>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void set_boards(string file, vector<Sudoku> &boards, vector<string> &names) {
	ifstream fin;
	fin.open(file);

	if (fin.is_open()) {
		for (int k = 0; k < 50; ++k) {
			vector<vector<int>> board;
			for (int j = 0; j < 9; ++j) {
				vector<int> nums;
				char num[1];
				for (int i = 0; i < 9; ++i) {
					fin >> num[0];
					//cout << num[0] << " ";
					nums.push_back(atoi(num));
				}
				//cout << endl;
				board.push_back(nums);
			}
			boards.push_back(Sudoku(board));
			//print(board);
		}
		fin.close();
	}
}

int main() {
	
	vector<vector<int>> board1= {{ 3, 4, 1, 0 }, { 0, 2, 0, 0 }, { 0, 0, 2, 0 }, { 0, 1, 4, 3 }};
	Sudoku game(board1);
	game.print_board();
	game.solve();
	game.print_board();
	
	vector<vector<int>> board2 = { { 2, 0, 0, 1 },{ 0, 0, 0, 0 },{ 4, 0, 1, 0 },{ 3, 1, 0, 2 } };
	Sudoku game2(board2);
	game2.print_board();
	game2.solve();
	game2.print_board();

	vector<vector<int>> board3 = { {0, 0, 3, 0, 2, 0, 6, 0, 0} , {9, 0, 0, 3, 0, 5, 0, 0, 1}, {0, 0, 1, 8, 0, 6, 4, 0, 0}, {0, 0, 8, 1, 0, 2, 9, 0, 0}, {7, 0, 0, 0, 0, 0, 0, 0, 8}, {0, 0, 6, 7, 0, 8, 2, 0, 0},
								   {0, 0, 2, 6, 0, 9, 5, 0, 0}, {8, 0, 0, 2, 0, 3, 0, 0, 9}, {0, 0, 5, 0, 1, 0, 3, 0, 0} };
	Sudoku game3(board3);
	game3.print_board();
	game3.solve();
	game3.print_board();

	vector<Sudoku> boards;
	vector<string> names;
	int sum = 0;
	set_boards("p096_sudoku.txt", boards, names);
	for (int i = 0; i < boards.size(); ++i) {
		boards[i].solve();
		sum += boards[i].sum_first_three();
	}
	cout << sum;
}

/*class Sudoku {
public:
Sudoku(const vector<vector<int>> &board_in) :
size(board_in.size()), square_size(sqrt(board_in.size())), board(board_in) {
set_board_choices();
}

Sudoku(string file, int size_in) :
size(size_in), square_size(sqrt(size_in)) {
ifstream fin;
fin.open(file);

if (fin.is_open()) {
for (int j = 0; j < size; ++j) {
vector<int> nums;
char num[1];
for (int i = 0; i < size; ++i) {
fin >> num[0];
nums.push_back(atoi(num));
}
board.push_back(nums);
}
fin.close();
}
}

void solve() {
vector<changes> changed_choices;
vector<int> indices(1, 0);
while (num_zeroes != 0) {
int choices_size_index = 0;
for (; !board_choices[choices_size_index].size(); ++choices_size_index);

choices &first_choices = board_choices[choices_size_index].back();
if (!choices_size_index || indices.back() >= first_choices.size()) {
//cout << "index inside if " << indices.back() << endl;
//cout << "reverese, index " << indices.back() << endl;
reverse(changed_choices, indices);
//print_board_choices();
continue;
}
//cout << "got past reverse\n";
int row_updated = first_choices.row;
int column_updated = first_choices.column;

set<int>::iterator itr = first_choices.nums.begin();
for (int i = 0; i < indices.back(); ++i, ++itr);
//cout << "index at line 39 " << indices.back() << endl;
board[row_updated][column_updated] = *(itr);
//cout << "Row " << row_updated << " Column " << column_updated << " changed to " << board[row_updated][column_updated] << endl;
--num_zeroes;

changed_choices.push_back(changes(row_updated, column_updated, board[row_updated][column_updated]));
first_choices.nums.erase(itr);
changed_choices.back().choices_added.push_back(first_choices);
board_choices[choices_size_index].pop_back();
update_board_choices(row_updated, column_updated, changed_choices);
indices.push_back(0);
//print_board_choices();
}
}

bool solved() {

}

int sum_first_three() {
return board[0][0] * 100 + board[0][1] * 10 + board[0][2];
}

void print_board() {
for (size_t r = 0; r < size; ++r) {
if (r % square_size == 0) {
cout << '\n';
}
for (size_t c = 0; c < size; ++c) {
if (c % square_size == 0) {
cout << "  ";
}
cout << setw(3) << board[r][c];
}
cout << '\n';
}
}

void print_board_choices() {
for (auto &i : board_choices) {
for (auto &j : i) {
cout << "Row " << j.row << " Column " << j.column << "  ";
print_set(j.nums);
cout << "\n";
}
}
}

int get_size() {
return size;
}

int get_square_size() {
return square_size;
}

private:
struct choices {
int row;
int column;
set<int> nums;

choices() {}

choices(int row_in, int column_in, int size_in, set<int> nums_in) :
row(row_in), column(column_in), nums(nums_in) {}

int size() {
return nums.size();
}
};

struct changes {
int row;
int column;
int value_removed;
// change to choices * for faster copying
vector<choices> choices_added;

changes() {}

changes(int row_in, int column_in, int value_removed_in) :
row(row_in), column(column_in), value_removed(value_removed_in) {}
};

const int size;
const int square_size;
int num_zeroes;
vector<vector<int>> board;
vector<vector<choices>> board_choices = vector<vector<choices>>(size + 1);

void set_board_choices() {
vector<set<int>> used_nums_in_rows(size);
vector<set<int>> used_nums_in_columns(size);
vector<set<int>> used_nums_in_squares(size);
set<int> all_choices;

num_zeroes = 0;

set_all_choices(all_choices);
populate_used_nums(used_nums_in_rows, used_nums_in_columns, used_nums_in_squares);

for (int r = 0; r < size; ++r) {
for (int c = 0; c < size; ++c) {
if (!board[r][c]) {
add_choices(r, c, all_choices, used_nums_in_rows, used_nums_in_columns, used_nums_in_squares);
++num_zeroes;
}
}
}
}

void set_all_choices(set<int> &all_choices) {
vector<int> choices;
for (int i = 1; i <= size; ++i) {
choices.push_back(i);
}
all_choices = set<int>(choices.begin(), choices.end());
}

void populate_used_nums(vector<set<int>> &rows, vector<set<int>> &columns, vector<set<int>> &squares) {
for (int r = 0; r < size; ++r) {
for (int c = 0; c < size; ++c) {
if (board[r][c]) {
rows[r].insert(board[r][c]);
columns[c].insert(board[r][c]);
squares[(c / square_size) + (r / square_size) * square_size].insert(board[r][c]);
}
}
}
}

void add_choices(int row, int column, const set<int> &all_choices, vector<set<int>> &rows,
vector<set<int>> &columns, vector<set<int>> &squares) {
set<int> grid_choices = all_choices;
for (int i : rows[row]) {
grid_choices.erase(i);
}
for (int i : columns[column]) {
grid_choices.erase(i);
}
for (int i : squares[(column / square_size) + (row / square_size) * square_size]) {
grid_choices.erase(i);
}

struct choices grid(row, column, grid_choices.size(), grid_choices);
board_choices[grid.size()].push_back(grid);
}

void reverse(vector<changes> &board_changes, vector<int> &indices) {
//cout << "Board choices before reverse: \n";
//print_board_choices();
//cout << "Index before pop: " << indices.back() << endl;
++num_zeroes;
indices.pop_back();
++indices.back();
//cout << "Index after pop and increment: " << indices.back() << endl;

while (board_changes.back().choices_added.size() > 1) {
choices &back_choices = board_changes.back().choices_added.back();
back_choices.nums.insert(board_changes.back().value_removed);
board_choices[back_choices.nums.size()].push_back(back_choices);

// alternatively just look in row before added back_choices
vector<choices>::iterator old_location = find_choices(back_choices.row, back_choices.column, board_choices);
board_choices[back_choices.nums.size() - 1].erase(old_location);
board_changes.back().choices_added.pop_back();
}
board[board_changes.back().row][board_changes.back().column] = 0;
choices &back_choices = board_changes.back().choices_added.back();
back_choices.nums.insert(board_changes.back().value_removed);
board_choices[back_choices.nums.size()].push_back(back_choices);

board_changes.pop_back();
//cout << "Board choices after reverse: \n\n";
//print_board_choices();
}

void update_board_choices(int row, int column, vector<changes> &changed_choices) {
int removed_value = board[row][column];

for (int c = 1; c < size; ++c) {
int current_column = (column + c) % size;
if (!board[row][current_column]) {
update_current_choices(row, current_column, removed_value, changed_choices);
}

}
for (int r = 1; r < size; ++r) {
int current_row = (row + r) % size;
if (!board[current_row][column]) {
update_current_choices(current_row, column, removed_value, changed_choices);
}
}
for (int r = 0; r < size; ++r) {
for (int c = 0; c < size; ++c) {
int current_row = (row + r) % square_size + square_size * (row / square_size);
int current_column = (column + c) % square_size + square_size * (column / square_size);
if (!board[current_row][current_column]) {
update_current_choices(current_row, current_column, removed_value, changed_choices);
}
}
}
}

void update_current_choices(int row, int column, int value, vector<changes> &changed_choices) {
vector<choices>::iterator choices_location = find_choices(row, column, board_choices);
if ((*choices_location).nums.erase(value) == 1) {
//cout << "Updating " << row << "  " << column << endl;
board_choices[(*choices_location).size()].push_back(*choices_location);
changed_choices.back().choices_added.push_back(*choices_location);
board_choices[(*choices_location).size() + 1].erase(choices_location);
//cout << "Board choices after updating: " << endl;
// print_board_choices();
return;
}
}

vector<choices>::iterator find_choices(int row, int column, const vector<vector<choices>> &location) {
for (vector<vector<choices>>::iterator i = board_choices.begin(); i != board_choices.end(); ++i) {
for (vector<choices>::iterator j = (*i).begin(); j != (*i).end(); ++j) {
if ((*j).row == row && (*j).column == column) {
return j;
}
}
}
return vector<choices>::iterator();
}

void print_set(const set<int> &s) {
for (int i : s) {
cout << setw(2) << i;
}
}
};*/