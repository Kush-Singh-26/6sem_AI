import sys

def dfs(row, col, graph, vis, dr, dc, path, n, m, directions):
    if row == n-1 and col == m-1:
        return True
    
    vis[row][col] = 1

    for i in range(4):
        nr, nc = row + dr[i], col + dc[i]

        if 0 <= nr < n and 0 <= nc < m and graph[nr][nc] == 1 and not vis[nr][nc]:
            path.append(directions[i])

            if dfs(nr, nc, graph, vis, dr, dc, path, n, m, directions):
                return True

            path.pop()

    return False

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
        path = []

        print("\nGrid entered is :")
        for row in grid:
            print(*(row))

        if grid[0][0] == 1:
            if dfs(0, 0, grid, vis, dr, dc, path, n, m, directions):
                print(f"Path found : {''.join(path)}")
            else:    
                print("Path not found")
        else:    
            print("Starting point blocked")
    except (ValueError, EOFError, IndexError):
        pass

if __name__ == "__main__":
    main()
