import heapq
import sys

def a_star_search(n, adj, start, target, h):
    # Priority queue stores (f_score, node)
    pq = [(h[start], start)]
    
    parent = [-1] * (n + 1)
    g_score = [float('inf')] * (n + 1)
    g_score[start] = 0
    
    while pq:
        f, u = heapq.heappop(pq)
        
        if u == target:
            path = []
            curr = target
            while curr != -1:
                path.append(curr)
                curr = parent[curr]
            path.reverse()
            
            print("Path found :", *path)
            print(f"Total Cost = {g_score[target]}")
            return
        
        if g_score[u] + h[u] < f:
            continue
            
        if u in adj:
            for v, w in adj[u]:
                if g_score[u] + w < g_score[v]:
                    parent[v] = u
                    g_score[v] = g_score[u] + w
                    f_score = g_score[v] + h[v]
                    heapq.heappush(pq, (f_score, v))
                    
    print("Target Unreachable")

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
            weight = int(next(it))
            if u not in adj: adj[u] = []
            if v not in adj: adj[v] = []
            adj[u].append((v, weight))
            adj[v].append((u, weight))
            
        start = int(next(it))
        target = int(next(it))
        
        h = []
        for _ in range(n + 1):
            h.append(int(next(it)))
            
        a_star_search(n, adj, start, target, h)
        print("23052247\nKush Singh\nCSE-22")
    except (StopIteration, ValueError, EOFError):
        pass

if __name__ == "__main__":
    main()
