#include<bits/stdc++.h>
#include <queue>
using namespace std;

const int INF = 1e9;

void aStarSearch(int n, vector<vector<pair<int, int>>>& adj, int start, int target, vector<int>& h){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    
    vector<int> parent(n+1, -1);
    vector<int> g_score(n+1, INF);
    g_score[start] = 0;
    pq.push({h[start], start});
    
    while(!pq.empty())
    {
        int f = pq.top().first;
        int u = pq.top().second;   
        pq.pop();
        
        if(u == target)
        {
            vector<int> path;
            for(int v = target; v != -1; v = parent[v]) 
                path.push_back(v);
            reverse(path.begin(), path.end());
            
            cout << "Path found : ";
            for(int i= 0;i<path.size();i++)
                cout << path[i] << " ";
            cout << "\nTotal Cost = " << g_score[target] << "\n";
            return;
        }
        
        if(g_score[u] + h[u] < f)
            continue;
        
        for(auto e : adj[u]){
            int v = e.first;
            int w = e.second;
            
            if(g_score[u] + w < g_score[v]){
                parent[v] = u;
                g_score[v] = g_score[u] + w;
                
                int f_score = g_score[v] + h[v];
                pq.push({f_score, v});
            }
        }
    }
    cout << "Target Unreachable\n";
}

int main()
{
    int n,m;
    cout << "Enter number of nodes and edges : ";
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    
    cout << "Enter edges (u v weight):\n";
        for (int i = 0; i < m; i++) {
            int u, v, weight; 
            cin >> u >> v >> weight;
            adj[u].push_back({v, weight}); 
            adj[v].push_back({u, weight}); 
        }
    
        int start, target;
        cout << "Enter start and target nodes: ";
        cin >> start >> target;
    
        vector<int> h(n + 1);
        cout << "Enter heuristics for nodes 0 to " << n << ":\n";
        for (int i = 0; i <= n; i++) cin >> h[i];
    
        aStarSearch(n, adj, start, target, h);
        cout << "23052247\nKush Singh\nCSE-22\n";
        return 0;
}

/*
    Output :
    Enter number of nodes and edges : 5 6
    Enter edges (u v weight):
    1 2 2
    1 3 4
    2 3 1
    2 4 7
    3 5 3
    4 5 1
    Enter start and target nodes: 1 5
    Enter heuristics for nodes 0 to 5:
    0 7 6 2 1 0
    Path found : 1 3 5
    Total Cost = 7
    23052247
    Kush Singh
    CSE-22
 */