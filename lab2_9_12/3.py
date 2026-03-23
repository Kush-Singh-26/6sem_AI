import sys

def dfs(row, col, graph, vis, dr, dc, path, all_paths, n, m, directions):
    if row == n-1 and col == m-1:
        all_paths.append("".join(path))
        return
    
    vis[row][col] = 1

    for i in range(4):
        nr, nc = row + dr[i], col + dc[i]

        if 0 <= nr < n and 0 <= nc < m and graph[nr][nc] == 1 and not vis[nr][nc]:
            path.append(directions[i])
            dfs(nr, nc, graph, vis, dr, dc, path, all_paths, n, m, directions)
            path.pop()

    vis[row][col] = 0

def main():
    try:
        line = input("Enter no. of rows & cols : ").split()
        if not line: return
        n, m = int(line[0]), int(line[1])

        print("Enter the grid : ")
        grid = []
        for _ in range(n):
            grid.append(list(map(int, input().split())))
            
        dr = [1, -1, 0, 0]
        dc = [0, 0, 1, -1]
        directions = "DURL"

        vis = [[0 for _ in range(m)] for _ in range(n)]
        all_paths = []

        print("\nGrid entered is :")
        for row in grid:
            print(*(row))

        if grid[0][0] == 1:
            dfs(0, 0, grid, vis, dr, dc, [], all_paths, n, m, directions)
            if not all_paths:
                print("No Paths")
            else:
                for p in all_paths:
                    print(p)
        else:
            print("Starting point blocked")
    except (ValueError, EOFError, IndexError):
        pass

if __name__ == "__main__":
    main()
