#include<bits/stdc++.h>

using namespace std;

string dir = "DURL";


void createRandomGrid(vector<vector<int>>&grid, int n, int m)
{
    srand(time(0));

    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            int val = (rand() % 100 < 70) ? 1 : 0;
            grid[i][j] = val;
        }
    }

    grid[0][0] = 1;
    grid[n-1][m-1] = 1;
}

void dfs(int row, int col, vector<vector<int>>& graph, vector<vector<int>>& vis, vector<int>& dr, vector<int>& dc, string& path, vector<string>& allPaths, int n, int m)
{
    if(row == n-1 && col == m-1)
    {
        allPaths.push_back(path);
        return;
    }
    
    vis[row][col] = 1;


    for(int i=0;i<4;i++)
    {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && graph[nr][nc] == 1 && !vis[nr][nc])
        {
            path.push_back(dir[i]);

            dfs(nr, nc, graph, vis, dr, dc, path, allPaths, n, m);

            path.pop_back();

        }
    }

    vis[row][col] = 0;
}

int main()
{
    cout << "Enter no. of rows & cols : ";

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    createRandomGrid(grid, n, m);
            
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    vector<vector<int>> vis(n, vector<int>(m, 0));

    string path = "";
    vector<string> allPaths;

    cout << "\nGrid Generated is :\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }

    if(grid[0][0] == 1)
    {
        dfs(0, 0, grid, vis, dr, dc, path, allPaths, n, m);
        if(allPaths.size() == 0)
            cout << "No Paths\n";
        else
        {
            for(auto x : allPaths)
                cout << x << "\n";
        }
    }
    else    
        cout << "Starting point blocked\n";
    
    return 0;
}