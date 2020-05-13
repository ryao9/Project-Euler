/*
Problem: Move n disks from pillar start (1) to pillar destination (3) 
    move n - 1 disks from pillar start (1) to pillar placeholder (2)
    move nth disk from pillar start (1) to pillar destination (3)
    move n - 1 disks from pillar placeholder (2) to pillar destination (3)
*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX_DISKS = 6;
static int num_move = 0;

void init_vector(vector<int> v, int size) {
    for (int i = size; i >= 1; --i) {
        v.push_back(i);
    }
}

void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
}

int get_place_holder(int start, int destination) {
    int place_holder;
    if (destination == 3) {
        (start == 2) ? place_holder = 1 : place_holder = 2;
    }
    else {
        (start == 1) ? place_holder = 2: place_holder = 1;
    }
    return place_holder;
}

void move_disk(int start, int destination, vector<int> pillars[]) {
    int moved_pillar = pillars[start].back();
    pillars[start].pop_back();
    pillars[destination].push_back(moved_pillar);

    for (int i = 0; i < 3; ++i) {
        cout << "Pillar" << i + 1 << "\n\n";
        print_vector(pillars[i]);
    }
}

void move_tower(int start, int destination, int n, vector<int> pillars[]) {
    if (n == 1) {
        move_disk(start, destination, pillars);
        num_move++;
    }
    else {
        int place_holder = get_place_holder(start, destination);
        move_tower(start, place_holder , n - 1, pillars);
        move_disk(start, place_holder, pillars);
        num_move++;
        move_tower(place_holder, destination, n - 1, pillars);     
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> pillars[3];
    init_vector(pillars[0], n);

    move_tower(1, 3, n, pillars);
    cout << num_move << endl;
}