import sys

def dfs(adj, src, vis, res):
    vis[src] = 1
    res.append(src)
    if src in adj:
        for ngb in adj[src]:
            if not vis[ngb]:
                dfs(adj, ngb, vis, res)

def main():
    try:
        input_data = sys.stdin.read().split()
        if not input_data: return
        it = iter(input_data)
        
        n = int(next(it))
        m = int(next(it))
        
        adj = {}
        for _ in range(m):
            x = int(next(it))
            y = int(next(it))
            if x not in adj: adj[x] = []
            if y not in adj: adj[y] = []
            adj[x].append(y)
            adj[y].append(x)

        vis = [0] * (n + 1)
        res = []
        
        # Original code starts DFS from node 1
        dfs(adj, 1, vis, res)

        print(*(res))
    except (StopIteration, ValueError, EOFError):
        pass

if __name__ == "__main__":
    main()
