import heapq
import sys

class Node:
    def __init__(self, node_id, h_cost):
        self.id = node_id
        self.h_cost = h_cost

    def __lt__(self, other):
        return self.h_cost < other.h_cost

def best_first_search(adj, start, target, h_values):
    # Min-priority queue: stores Node objects
    pq = [Node(start, h_values[start])]
    
    visited = {start: True}
    parent = {start: None}
    expanded_nodes = []

    found = False

    while pq:
        current = heapq.heappop(pq)
        u = current.id

        expanded_nodes.append(u)

        if u == target:
            found = True
            break

        # Check neighbors
        if u in adj:
            for v in adj[u]:
                if v not in visited:
                    visited[v] = True
                    parent[v] = u
                    heapq.heappush(pq, Node(v, h_values[v]))

    print("\nRESULT")
    print("Expanded Nodes: " + " -> ".join(expanded_nodes))

    if found:
        print("Path Found: ", end="")
        path = []
        crawl = target
        while crawl is not None:
            path.append(crawl)
            crawl = parent[crawl]
        path.reverse()
        print(" -> ".join(path))
    else:
        print("Path Found: No path exists.")

def main():
    try:
        print("Enter number of Nodes and Edges: ", end="", flush=True)
        line1 = sys.stdin.readline().split()
        if not line1: return
        n = int(line1[0])
        m = int(line1[1])

        adj = {}
        print("Enter Edges (Source Destination) :")
        for _ in range(m):
            edge = sys.stdin.readline().split()
            if not edge: break
            u, v = edge[0], edge[1]
            if u not in adj: adj[u] = []
            adj[u].append(v)

        print("Enter Start Node and Goal Node: ", end="", flush=True)
        line2 = sys.stdin.readline().split()
        if not line2: return
        start, target = line2[0], line2[1]

        print(f"Enter Heuristic value for {n} nodes (Node Value) :")
        h_values = {}
        for _ in range(n):
            h_line = sys.stdin.readline().split()
            if not h_line: break
            node, val = h_line[0], int(h_line[1])
            h_values[node] = val

        best_first_search(adj, start, target, h_values)
        print("23052247\nKush Singh\nCSE-22")
    except (ValueError, EOFError, IndexError):
        pass

if __name__ == "__main__":
    main()
