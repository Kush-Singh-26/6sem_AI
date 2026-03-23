#include<bits/stdc++.h>

using namespace std;

struct Node{
    int x, y;
    string path;
};

void bfs(vector<vector<int>>& grid, int n, int m)
{
    if(grid[0][0] == 0)
    {
        cout << "Start is blocked\n";
        return;
    }

    queue<Node> q;
    q.push({0, 0, ""});

    vector<vector<int>> vis(n, vector<int>(m,0));
    vis[0][0] =1;

    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    string dir = "DURL";

    while(!q.empty())
    {
        Node curr = q.front();
        q.pop();

        int r = curr.x;
        int c = curr.y;
        string path = curr.path;

        if(r == n-1 && c == m-1)
        {
            cout << "Shortest Path\n";
            cout << path << "\n";
            return;
        }

        for(int i=0;i<4;i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !vis[nr][nc])
            {
                vis[nr][nc] = 1;
                q.push({nr, nc, path + dir[i]});
            }
        }
    }

    cout << "No path found\n";
}

int main()
{
    cout << "Enter no. of rows & cols : ";

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter the grid : \n";

    for(int i=0;i<n;i++)
        for(int j =0;j<m;j++)
            cin >> grid[i][j];
            
    

    cout << "\nGrid entered is :\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }

    bfs(grid, n, m);
    
    return 0;
}