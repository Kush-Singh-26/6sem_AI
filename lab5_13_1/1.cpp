#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

struct Node {
    char id;
    int h_cost;

    Node(char i, int h) : id(i), h_cost(h) {}

    bool operator >(const Node& other) const {
        return h_cost > other.h_cost;
    }
};

void bestFirstSearch(map<char, vector<char>>& adj, char start, char target, map<char, int>& h_values) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    map<char, bool> visited;
    map<char, char> parent;
    vector<char> expanded_nodes; 

    // Initialize
    pq.push(Node(start, h_values[start]));
    visited[start] = true;
    parent[start] = '\0'; 

    bool found = false;

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        char u = current.id;

        expanded_nodes.push_back(u);

        if (u == target) {
            found = true;
            break;
        }

        // Check neighbors
        for (char v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                pq.push(Node(v, h_values[v]));
            }
        }
    }

    cout << "\nRESULT" << endl;
    cout << "Expanded Nodes: ";
    for (size_t i = 0; i < expanded_nodes.size(); i++) {
        cout << expanded_nodes[i];
        if (i < expanded_nodes.size() - 1) cout << " -> ";
    }
    cout << endl;

    if (found) {
        cout << "Path Found: ";
        stack<char> path;
        char crawl = target;
        while (crawl != '\0') {
            path.push(crawl);
            crawl = parent[crawl];
        }

        while (!path.empty()) {
            cout << path.top();
            path.pop();
            if (!path.empty()) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "Path Found: No path exists." << endl;
    }
}

int main() {
    int n, m;
    map<char, vector<char>> adj;
    map<char, int> h_values;

    cout << "Enter number of Nodes and Edges: ";
    if (!(cin >> n >> m)) return 0;

    cout << "Enter Edges (Source Destination) :\n";
    for(int i = 0; i < m; i++) {
        char u, v;
        cin >> u >> v;
        adj[u].push_back(v); 
    }

    char start, target;
    cout << "Enter Start Node and Goal Node: ";
    cin >> start >> target;

    cout << "Enter Heuristic value for " << n << " nodes (Node Value) :\n";
    for(int i = 0; i < n; i++) {
        char node;
        int val;
        cin >> node >> val;
        h_values[node] = val;
    }

    bestFirstSearch(adj, start, target, h_values);
    
    cout << "23052247\nKush Singh\nCSE-22\n";
    return 0;
}

/*
    Output :
    Enter number of Nodes and Edges: 4 4
    Enter Edges (Source Destination) :
    A B
    A C
    B D
    C D
    Enter Start Node and Goal Node: A D
    Enter Heuristic value for 4 nodes (Node Value) e.g., W 10:
    A 5
    B 3
    C 4
    D 0
    
    RESULT
    Expanded Nodes: A -> B -> D
    Path Found: A -> B -> D
    23052247
    Kush Singh
    CSE-22
 */