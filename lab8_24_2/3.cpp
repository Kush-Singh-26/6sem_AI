#include <bits/stdc++.h>
#include <tuple>

using namespace std;

void waterJug(int jug1cap, int jug2cap, int jug3cap, int target) {
  queue<tuple<int, int, int>> q;
  set<tuple<int, int, int>> visited;
  map<tuple<int, int, int>, tuple<int, int, int>> parent;

  q.push({0, 0, 0});
  visited.insert({0, 0, 0});

  tuple<int, int, int> goal = {-1, -1, -1};

  while (!q.empty()) {
    auto state = q.front();
    q.pop();

    int a = get<0>(state);
    int b = get<1>(state);
    int c = get<2>(state);

    if (a == target || b == target || c == target) {
      goal = state;
      break;
    }

    vector<tuple<int, int, int>> next_states = {
        // fill operations
        {jug1cap, b, c},
        {a, jug2cap, c},
        {a, b, jug3cap},

        // empty operations
        {0, b, c},
        {a, 0, c},
        {a, b, 0},

        // 1->2
        {a - min(a, jug2cap - b), b + min(a, jug2cap - b), c},

        // 1->3
        {a - min(a, jug3cap - c), b, c + min(a, jug3cap - c)},

        // 2->1
        {a + min(b, jug1cap - a), b - min(b, jug1cap - a), c},

        // 2->3
        {a, b - min(b, jug3cap - c), c + min(b, jug3cap - c)},

        // 3->1
        {a + min(c, jug1cap - a), b, c - min(c, jug1cap - a)},

        // 3->2
        {a, b + min(c, jug2cap - b), c - min(c, jug2cap - b)}};

    for (auto nxt : next_states) {
      if (visited.find(nxt) == visited.end()) {
        visited.insert(nxt);
        parent[nxt] = state;
        q.push(nxt);
      }
    }
  }

  // no solution
  if (get<0>(goal) == -1) {
    cout << "no solution\n";
    return;
  }

  vector<tuple<int, int, int>> path;
  while (goal != make_tuple(0, 0, 0)) {
    path.push_back(goal);
    goal = parent[goal];
  }
  path.push_back({0, 0, 0});

  reverse(path.begin(), path.end());

  cout << "Solution\n";
  for (auto p : path) {
    cout << "(" << get<0>(p) << ", " << get<1>(p) << ", " << get<2>(p) << ")\n";
  }
}

int main() { 
    
    int j1, j2, j3, target;
    cout << "Enter capacity of each jug & target: ";
    cin >> j1 >> j2 >> j3 >> target;
    
    waterJug(j1, j2, j3, target);
    
    cout << "23052247\nKush Singh\nCSE 22\n";
    
    return 0; 
}
