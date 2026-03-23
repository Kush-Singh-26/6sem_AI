import collections
import sys

class Node:
    def __init__(self, x, y, path):
        self.x = x
        self.y = y
        self.path = path

def bfs(grid, n, m):
    if grid[0][0] == 0:
        print("Start is blocked")
        return

    queue = collections.deque([Node(0, 0, "")])
    vis = [[0 for _ in range(m)] for _ in range(n)]
    vis[0][0] = 1

    dr = [1, -1, 0, 0]
    dc = [0, 0, 1, -1]
    directions = "DURL"

    while queue:
        curr = queue.popleft()
        r, c, path = curr.x, curr.y, curr.path

        if r == n-1 and c == m-1:
            print("Shortest Path")
            print(path)
            return

        for i in range(4):
            nr, nc = r + dr[i], c + dc[i]

            if 0 <= nr < n and 0 <= nc < m and grid[nr][nc] == 1 and not vis[nr][nc]:
                vis[nr][nc] = 1
                queue.append(Node(nr, nc, path + directions[i]))

    print("No path found")

def main():
    try:
        line = input("Enter no. of rows & cols : ").split()
        if not line: return
        n, m = int(line[0]), int(line[1])

        print("Enter the grid : ")
        grid = []
        for _ in range(n):
            grid.append(list(map(int, input().split())))
            
        print("\nGrid entered is :")
        for row in grid:
            print(*(row))

        bfs(grid, n, m)
    except (ValueError, EOFError, IndexError):
        pass

if __name__ == "__main__":
    main()
