#include<bits/stdc++.h>

using namespace std;

struct Node{
    int id;
    int h_cost;

    Node(int i, int h) : id(i), h_cost(h) {}

    bool operator >(const Node& other) const {
        return h_cost > other.h_cost;
    }
};

void bestFirstSearch(int n, vector<vector<int>>& adj, int start, int target, vector<int>& h_values) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    pq.push(Node(start, h_values[start]));
    visited[start] = true;

    bool found = false;

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.id;

        cout << "Visiting Node: " << u << " | Heuristic: " << current.h_cost << endl;

        if (u == target) {
            cout << "\nTarget Found at Node " << u << endl;
            found = true;
            break;
        }

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                pq.push(Node(v, h_values[v]));
            }
        }
    }

    if (found) {
        cout << "Path to Target: ";
        stack<int> path;
        int crawl = target;

        while (crawl != -1) {
            path.push(crawl);
            crawl = parent[crawl];
        }

        while (!path.empty()) {
            int p = path.top();
            path.pop();
            cout << p;
            if (!path.empty()) cout << " -> ";
        }
        cout << "\n";
    } else {
        cout << "Target is unreachable\n";
    }
}

int main() {
    int n, m;
    cout << "Enter no. of node & edges : ";
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    cout << "enter src & dest of each edge :\n";
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start, target;
    cout << "Enter Start Node and Target Node: ";
    cin >> start >> target;

    vector<int> h_values(n + 1);
    cout << "Enter heuristic value for each node (from 0 to " << n << "):\n";
    for(int i = 0; i <= n; i++) {
        cin >> h_values[i];
    }

    bestFirstSearch(n, adj, start, target, h_values);

    return 0;
}