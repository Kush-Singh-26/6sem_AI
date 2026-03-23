#include<bits/stdc++.h>
using namespace std;

void dls(vector<vector<int>>& adj, int src, int limit, vector<int>& path, vector<int>& vis)
{
    if(limit < 0)
        return;
    vis[src] = 1;
    path.push_back(src);
    for(int v : adj[src])
    {
        if(!vis[v])
            dls(adj, v, limit-1, path, vis);
    }
       
}

int main()
{
    cout << "a b c d e f g\n";
    cout << "0 1 2 3 4 5 6\n";
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n);
    int x,y;
    for(int i= 0;i<m;i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int src, limit; cin >> src >> limit;
    vector<int> vis(n, 0);
    vector<int> path;
    dls(adj, src, limit, path, vis);
    
    for(int i= 0;i<path.size();i++)
        cout << path[i] << " ";
    cout << "\n";
    // This mapping is done just to view the output easily.
    string mapping[] = {"a", "b", "c", "d", "e", "f", "g"};
    for(int i= 0;i<path.size();i++)
        cout << mapping[path[i]] << " ";
    cout << "\n";
}