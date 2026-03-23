import heapq
import sys

class Node:
    def __init__(self, node_id, h_cost):
        self.id = node_id
        self.h_cost = h_cost

    def __lt__(self, other):
        return self.h_cost < other.h_cost

def best_first_search(n, adj, start, target, h_values):
    pq = [Node(start, h_values[start])]
    visited = [False] * (n + 1)
    parent = [-1] * (n + 1)
    visited[start] = True

    found = False

    while pq:
        current = heapq.heappop(pq)
        u = current.id

        print(f"Visiting Node: {u} | Heuristic: {current.h_cost}")

        if u == target:
            print(f"\nTarget Found at Node {u}")
            found = True
            break

        if u in adj:
            for v in adj[u]:
                if not visited[v]:
                    visited[v] = True
                    parent[v] = u
                    heapq.heappush(pq, Node(v, h_values[v]))

    if found:
        print("Path to Target: ", end="")
        path = []
        crawl = target
        while crawl != -1:
            path.append(crawl)
            crawl = parent[crawl]
        path.reverse()
        print(" -> ".join(map(str, path)))
    else:
        print("Target is unreachable")

def main():
    try:
        input_data = sys.stdin.read().split()
        if not input_data: return
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

        h_values = []
        for _ in range(n + 1):
            h_values.append(int(next(it)))

        best_first_search(n, adj, start, target, h_values)
    except (StopIteration, ValueError, EOFError):
        pass

if __name__ == "__main__":
    main()
