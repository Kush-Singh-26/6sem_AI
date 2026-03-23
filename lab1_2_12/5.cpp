#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int src, vector<int>& vis, vector<int>& res)
{
    vis[src] = 1;
    res.push_back(src);
    for(auto ngb : adj[src])
    {
        if(!vis[ngb])
            dfs(adj, ngb, vis, res);
    }
}


int main()
{
    cout << "Enter no of vertices & edges : ";
    int n,m;
    cin >> n >> m;
    cout << "Enter each edge's src and dst node\n";
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> vis(n+1, 0);
    vector<int> res;
    dfs(adj, 1, vis, res);

    for(int i= 0;i<res.size();i++)
        cout << res[i] << " ";
    
    cout << "\n";

    return 0;
}