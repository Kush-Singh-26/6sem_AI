#include<bits/stdc++.h>
using namespace std;

void printPath(vector<int>&parent, int goal)
{
    if(parent[goal] == -1)
        return;
    
    vector<int>path;
    int curr = goal;
    while(curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr]; 
    }
    reverse(path.begin(), path.end());

    cout << "Optimal Path : \n";
    for(int node : path)
        cout << node << " ";
    cout << "\n";
}

void USC(vector<pair<int,int>>adj[], int n, int start, int goal)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {cost, node}
    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty())
    {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(u == goal)
        {
            cout << "min cost : " << cost << "\n";
            printPath(parent, goal);
            return;
        }

        if(cost > dist[u])
            continue;
        for(auto e : adj[u])
        {
            int w = e.first;
            int v = e.second;
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Path not found\n";

}


int main()
{
    int n,m;
    cout << "Enter the number of vertex and edges of the graph : ";
    cin >> n >> m;
    cout << "Enter each edge's start node, end node and cost : \n";
    vector<pair<int,int>>adj[n+1];
    int u,v,c;
    for(int i = 0;i<m;i++)
    {
        cin >> u >> v >> c;
        adj[u].push_back({c,v});
    }

    int start, goal;
    cout << "Enter the start and goal node : ";
    cin >> start >> goal;
    USC(adj, n, start, goal);
    
    cout << "23052247\nKush Singh\nCSE-22\n";
    return 0;
}

/*
    Output :
    Enter the number of vertex and edges of the graph : 5 6
    Enter each edge's start node, end node and cost :
    1 2 2
    1 3 4
    2 3 1
    2 4 7
    3 5 3
    4 5 1
    Enter the start and goal node : 1 5
    min cost : 6
    Optimal Path :
    1 2 3 5
    23052247
    Kush Singh
    CSE-22
 */