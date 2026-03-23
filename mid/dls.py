import sys

def dls(adj, src, limit, path, vis):
    if limit < 0:
        return
    vis[src] = 1
    path.append(src)
    for v in adj[src]:
        if not vis[v]:
            dls(adj, v, limit - 1, path, vis)

def main():
    print("a b c d e f g")
    print("0 1 2 3 4 5 6")
    
    try:
        input_data = sys.stdin.read().split()
        if not input_data:
            return
            
        it = iter(input_data)
        n = int(next(it))
        m = int(next(it))
        
        adj = [[] for _ in range(n)]
        for _ in range(m):
            x = int(next(it))
            y = int(next(it))
            adj[x].append(y)
            adj[y].append(x)
            
        src = int(next(it))
        limit = int(next(it))
        
        vis = [0] * n
        path = []
        dls(adj, src, limit, path, vis)
        
        print(*(path))
        
        # This mapping is done just to view the output easily.
        mapping = ["a", "b", "c", "d", "e", "f", "g"]
        print(*(mapping[p] for p in path))
        
    except (EOFError, StopIteration, ValueError):
        pass

if __name__ == "__main__":
    main()
