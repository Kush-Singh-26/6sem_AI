#include<bits/stdc++.h>

using namespace std;

string dir = "DURL";

bool dfs(int row, int col, vector<vector<int>>& graph, vector<vector<int>>& vis, vector<int>& dr, vector<int>& dc, string& path, int n, int m)
{
    if(row == n-1 && col == m-1)
        return true;
    
    vis[row][col] = 1;


    for(int i=0;i<4;i++)
    {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && graph[nr][nc] == 1 && !vis[nr][nc])
        {
            path.push_back(dir[i]);

            if(dfs(nr, nc, graph, vis, dr, dc, path, n, m))
                return true;

            path.pop_back();
        }
    }

    return false;
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
            
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    vector<vector<int>> vis(n, vector<int>(m, 0));

    string path = "";

    cout << "\nGrid entered is :\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }

    if(grid[0][0] == 1)
    {
        if(dfs(0, 0, grid, vis, dr, dc, path, n, m))
            cout << "Path found : " << path << "\n";
        else    
            cout << "Path not found\n";
    }
    else    
        cout << "Starting point blocked\n";
    
        return 0;
}
