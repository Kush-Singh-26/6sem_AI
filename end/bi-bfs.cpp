#include<bits/stdc++.h>

using namespace std;

void printPath(vector<int>& parent_src, vector<int>& parent_dest, int t, int src, int dest)
{
    vector<int> path;

    int curr = t;
    path.push_back(curr);

    while(curr != src)
    {
        curr = parent_src[curr];
        path.push_back(curr);
    }

    reverse(path.begin(), path.end());

    curr = t;
    while(curr != dest)
    {
        curr = parent_dest[curr];
        path.push_back(curr);
    }

    for(int i : path)
        cout << i << " ";
    cout << "\n";
}

void biBFS(vector<int> adj[], int src, int dest, int n)
{
    if(src == dest)
    {
        cout << "src & dest are same.\n";
        return;
    }
    queue<int> q_src, q_dest;

    vector<int> vis_src(n+1, 0);
    vector<int> vis_dest(n+1, 0);

    vector<int> parent_src(n+1, -1);
    vector<int> parent_dest(n+1, -1);

    q_src.push(src);
    q_dest.push(dest);

    vis_src[src] = 1;
    vis_dest[dest] = 1;

    while(!q_src.empty() && !q_dest.empty())
    {
        // From src
        if(!q_src.empty())
        {
            int u = q_src.front();
            q_src.pop();

            for(int v : adj[u])
            {
                if(!vis_src[v])
                {
                    vis_src[v] = 1;
                    parent_src[v] = u;
                    q_src.push(v);

                    if(vis_dest[v])
                    {
                        printPath(parent_src, parent_dest, v, src, dest);
                        return;
                    }
                }
            }
        }

        // From dest
        if(!q_dest.empty())
        {
            int u = q_dest.front();
            q_dest.pop();

            for(int v : adj[u])
            {
                if(!vis_dest[v])
                {
                    vis_dest[v] = 1;
                    parent_dest[v] = u;
                    q_dest.push(v);

                    if(vis_src[v])
                    {
                        printPath(parent_src, parent_dest, v, src, dest);
                        return;
                    }
                }
            }
        }
    }

    cout << "No path exists\n";
}

int main()
{
    int n,m;
    cout << "Enter no. of node & edges : ";
    cin >> n >> m;
    cout << "enter src & dest of each edge :\n";
    vector<int> adj[n+1];

    int u,v;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Enter src & dest : ";
    int src, dest;
    cin >> src >> dest;

    biBFS(adj, src, dest, n);

    return 0;
}