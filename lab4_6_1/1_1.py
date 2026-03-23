import heapq
import sys

def best_first_search(n, adj, start, target, h):
    # Min-priority queue: stores (heuristic_value, node_id)
    pq = [(h[start], start)]
    
    parent = [-1] * (n + 1)
    vis = [False] * (n + 1)
    vis[start] = True

    while pq:
        h_val, u = heapq.heappop(pq)

        if u == target:
            # Reconstruct path
            path = []
            curr = target
            while curr != -1:
                path.append(curr)
                curr = parent[curr]
            path.reverse()

            print("Path found: " + " -> ".join(map(str, path)))
            return

        if u in adj:
            for v in adj[u]:
                if not vis[v]:
                    vis[v] = True
                    parent[v] = u
                    heapq.heappush(pq, (h[v], v))
                    
    print("Target unreachable")

def main():
    try:
        input_data = sys.stdin.read().split()
        if not input_data:
            return
        it = iter(input_data)
        
        n = int(next(it))
        m = int(next(it))
        
        adj = {}
        for _ in range(m):
            u = int(next(it))
            v = int(next(it))
            if u not in adj: adj[u] = []
            if v not in adj: adj[v] = []
            adj[u].append(v)
            adj[v].append(u)

        start = int(next(it))
        target = int(next(it))

        h = []
        for _ in range(n + 1):
            h.append(int(next(it)))

        best_first_search(n, adj, start, target, h)
    except (StopIteration, ValueError, EOFError):
        pass

if __name__ == "__main__":
    main()
