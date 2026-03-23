import sys
import collections

def bfs(adj, src, vis, res):
    vis[src] = 1
    queue = collections.deque([src])

    while queue:
        node = queue.popleft()
        res.append(node)

        if node in adj:
            for ngb in adj[node]:
                if not vis[ngb]:
                    vis[ngb] = 1
                    queue.append(ngb)

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
        
        # Original code starts BFS from node 1
        bfs(adj, 1, vis, res)

        print(*(res))
    except (StopIteration, ValueError, EOFError):
        pass

if __name__ == "__main__":
    main()
