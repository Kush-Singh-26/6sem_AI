import sys

def print_path(parent_src, parent_dest, m, src, dest):
    path_src = []
    curr = m
    while curr != -1:
        path_src.append(curr)
        if curr == src: break
        curr = parent_src[curr]
    path_src.reverse()

    path_dest = []
    curr = parent_dest[m]
    while curr != -1:
        path_dest.append(curr)
        if curr == dest: break
        curr = parent_dest[curr]
    
    full_path = path_src + path_dest
    print("Path found:", *(full_path))

def bidirectional_dfs(adj, src, dest, n):
    if src == dest:
        print("src & dest are same.")
        return

    s_src = [src]
    s_dest = [dest]

    vis_src = [0] * n
    vis_dest = [0] * n
    parent_src = [-1] * n
    parent_dest = [-1] * n

    vis_src[src] = 1
    vis_dest[dest] = 1

    while s_src and s_dest:
        # Forward DFS Step
        if s_src:
            u = s_src.pop()
            for v in range(n):
                if adj[u][v] == 1 and not vis_src[v]:
                    vis_src[v] = 1
                    parent_src[v] = u
                    s_src.append(v)
                    if vis_dest[v]:
                        print_path(parent_src, parent_dest, v, src, dest)
                        return

        # Backward DFS Step
        if s_dest:
            u = s_dest.pop()
            for v in range(n):
                if adj[u][v] == 1 and not vis_dest[v]:
                    vis_dest[v] = 1
                    parent_dest[v] = u
                    s_dest.append(v)
                    if vis_src[v]:
                        print_path(parent_src, parent_dest, v, src, dest)
                        return

    print("No path exists")

def main():
    try:
        input_data = sys.stdin.read().split()
        if not input_data: return
        it = iter(input_data)
        
        n = int(next(it))
        adj = []
        for i in range(n):
            row = []
            for j in range(n):
                row.append(int(next(it)))
            adj.append(row)

        src = int(next(it))
        dest = int(next(it))

        bidirectional_dfs(adj, src, dest, n)
    except (StopIteration, ValueError, EOFError):
        pass

if __name__ == "__main__":
    main()
