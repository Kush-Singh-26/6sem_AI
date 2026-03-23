#include<bits/stdc++.h>

using namespace std;

void printPath(vector<int>& parent_src, vector<int>& parent_dest, int m, int src, int dest)
{
    vector<int> path;

    int curr = m;
    path.push_back(curr);

    while(curr != src)
    {
        curr = parent_src[curr];
        path.push_back(curr);
    }

    reverse(path.begin(), path.end());

    curr = m;
    while(curr != dest)
    {
        curr = parent_dest[curr];
        path.push_back(curr);
    }

    cout << "Path found: ";
    for(int i : path)
        cout << i << " ";
    cout << "\n";
}

void biDFS(vector<vector<int>>& adj, int src, int dest, int n)
{
    if(src == dest)
    {
        cout << "src & dest are same.\n";
        return;
    }

    stack<int> s_src, s_dest;

    vector<int> vis_src(n, 0);
    vector<int> vis_dest(n, 0);

    vector<int> parent_src(n, -1);
    vector<int> parent_dest(n, -1);

    s_src.push(src);
    s_dest.push(dest);

    vis_src[src] = 1;
    vis_dest[dest] = 1;

    while(!s_src.empty() && !s_dest.empty())
    {
        // Forward DFS Step
        if(!s_src.empty())
        {
            int u = s_src.top();
            s_src.pop();

            for(int v = 0; v < n; v++)
            {
                if(adj[u][v] == 1 && !vis_src[v])
                {
                    vis_src[v] = 1;
                    parent_src[v] = u;
                    s_src.push(v);

                    if(vis_dest[v])
                    {
                        printPath(parent_src, parent_dest, v, src, dest);
                        return;
                    }
                }
            }
        }

        //  Backward DFS Step
        if(!s_dest.empty())
        {
            int u = s_dest.top();
            s_dest.pop();

            for(int v = 0; v < n; v++)
            {
                if(adj[u][v] == 1 && !vis_dest[v])
                {
                    vis_dest[v] = 1;
                    parent_dest[v] = u;
                    s_dest.push(v);

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
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    cout << "Enter Adjacency Matrix (" << n << "x" << n << "):\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }

    int src, dest;
    cout << "Enter Source and Destination: ";
    cin >> src >> dest;

    biDFS(adj, src, dest, n);

    return 0;
}