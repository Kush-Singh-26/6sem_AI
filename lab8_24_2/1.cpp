#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void waterJug(int jug1_cap, int jug2_cap, int target) {
    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    map<pair<int, int>, pair<int, int>> parent;

    q.push({0, 0});
    visited.insert({0, 0});
    pair<int, int> goal = {-1, -1};

    while (!q.empty()) {
        auto state = q.front();
        q.pop();

        int a = state.first;
        int b = state.second;
        

        // Check if target is reached
        if (a == target || b == target) {
            goal = state;
            break;
        }

        vector<pair<int, int>> next_states = {
            {jug1_cap, b}, // Fill Jug 1
            {a, jug2_cap}, // Fill Jug 2
            {0, b},        // Empty Jug 1
            {a, 0},        // Empty Jug 2
            // Pour Jug 1 to Jug 2
            {a - min(a, jug2_cap - b), b + min(a, jug2_cap - b)},
            // Pour Jug 2 to Jug 1
            {a + min(b, jug1_cap - a), b - min(b, jug1_cap - a)}
        };

        for (auto nxt : next_states) {
            if (visited.find(nxt) == visited.end()) {
                visited.insert(nxt);
                parent[nxt] = state;
                q.push(nxt);
            }
        }
    }

    // Reconstruct and print path
    if (goal.first == -1) {
        cout << "No solution possible.\n";
        return;
    }

    vector<pair<int, int>> path;
    while (goal != make_pair(0, 0)) {
        path.push_back(goal);
        goal = parent[goal];
    }
    path.push_back({0, 0});
    reverse(path.begin(), path.end());

    cout << "Solution Path:\n";
    for (auto p : path) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }
}

int main() {
    int jug1, jug2, target;
    cout << "Enter Jug1 Capacity: ";
    cin >> jug1;
    cout << "Enter Jug2 Capacity: ";
    cin >> jug2;
    cout << "Enter Target Amount: ";
    cin >> target;
    
    waterJug(jug1, jug2, target);
    cout << "23052247\nKush Singh\nCSE-22\n";
    return 0;
}

/*
    Output :
    Enter Jug1 Capacity: 4
    Enter Jug2 Capacity: 3
    Enter Target Amount: 2
    Solution Path:
    (0, 0)
    (0, 3)
    (3, 0)
    (3, 3)
    (4, 2)
    23052247
    Kush Singh
    CSE-22
 */