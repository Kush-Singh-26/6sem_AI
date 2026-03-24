#include <iostream>
using namespace std;

int G[4][4] = {
    {0,1,1,1},
    {1,0,1,0},
    {1,1,0,1},
    {1,0,1,0}
};

int color[4];

// Check if it's safe to assign color c to node v
bool isSafe(int v, int c) {
    for (int i = 0; i < 4; i++) {
        if (G[v][i] && color[i] == c)
            return false;
    }
    return true;
}

// Backtracking function
bool solve(int v) {
    if (v == 4) return true;

    for (int c = 1; c <= 3; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (solve(v + 1)) return true;
            color[v] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    if (solve(0)) {
        for (int i = 0; i < 4; i++)
            cout << "Node " << i << " -> Color " << color[i] << endl;
    }
}