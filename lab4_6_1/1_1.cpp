#include <bits/stdc++.h>
using namespace std;

void bestFirstSearch(int n, vector<vector<int>>& adj, int start, int target, vector<int>& h) {
    // Min-priority queue: stores {heuristic_value, node_id}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int> parent(n + 1, -1);
    vector<bool> vis(n + 1, false);

    pq.push({h[start], start});
    vis[start] = true;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == target) {
            // Reconstruct path using a simple vector
            vector<int> path;
            for (int v = target; v != -1; v = parent[v]) path.push_back(v);
            reverse(path.begin(), path.end());

            cout << "Path found: ";
            for (int i = 0; i < path.size(); i++) 
                cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
            cout << endl;
            return;
        }

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                parent[v] = u;
                pq.push({h[v], v});
            }
        }
    }
    cout << "Target unreachable\n";
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    int start, target;
    cin >> start >> target;

    vector<int> h(n + 1);
    for (int i = 0; i <= n; i++) cin >> h[i];

    bestFirstSearch(n, adj, start, target, h);
    return 0;
}