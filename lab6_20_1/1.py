import heapq
import sys

def print_path(parent, goal):
    if parent[goal] == -1 and goal != -1: # Assuming start has parent -1
        # Check if goal is start
        pass
    
    path = []
    curr = goal
    while curr != -1:
        path.append(curr)
        curr = parent[curr]
    path.reverse()

    if path:
        print("Optimal Path : ")
        print(*(path))

def usc(adj, n, start, goal):
    # pq stores (cost, node)
    pq = [(0, start)]
    dist = [float('inf')] * (n + 1)
    parent = [-1] * (n + 1)
    dist[start] = 0
    
    while pq:
        cost, u = heapq.heappop(pq)

        if u == goal:
            print(f"min cost : {cost}")
            print_path(parent, goal)
            return

        if cost > dist[u]:
            continue
            
        if u in adj:
            for w, v in adj[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    parent[v] = u
                    heapq.heappush(pq, (dist[v], v))

    print("Path not found")

def main():
    try:
        # For Uniform Cost Search input
        print("Enter the number of vertex and edges of the graph : ", end="", flush=True)
        line1 = sys.stdin.readline().split()
        if not line1: return
        n = int(line1[0])
        m = int(line1[1])
        
        print("Enter each edge's start node, end node and cost : ")
        adj = {}
        for _ in range(m):
            edge = sys.stdin.readline().split()
            if not edge: break
            u, v, c = map(int, edge)
            if u not in adj: adj[u] = []
            adj[u].append((c, v))

        print("Enter the start and goal node : ", end="", flush=True)
        line_sg = sys.stdin.readline().split()
        if not line_sg: return
        start = int(line_sg[0])
        goal = int(line_sg[1])
        
        usc(adj, n, start, goal)
        print("23052247\nKush Singh\nCSE-22")
    except (ValueError, EOFError, IndexError):
        pass

if __name__ == "__main__":
    main()
