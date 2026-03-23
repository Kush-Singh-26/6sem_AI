import collections
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
    print(*(full_path))

def bidirectional_bfs(adj, src, dest, n):
    if src == dest:
        print("src & dest are same.")
        return

    q_src = collections.deque([src])
    q_dest = collections.deque([dest])

    vis_src = [0] * (n + 1)
    vis_dest = [0] * (n + 1)
    parent_src = [-1] * (n + 1)
    parent_dest = [-1] * (n + 1)

    vis_src[src] = 1
    vis_dest[dest] = 1

    while q_src and q_dest:
        # From src
        if q_src:
            u = q_src.popleft()
            if u in adj:
                for v in adj[u]:
                    if not vis_src[v]:
                        vis_src[v] = 1
                        parent_src[v] = u
                        q_src.append(v)

                        if vis_dest[v]:
                            print_path(parent_src, parent_dest, v, src, dest)
                            return

        # From dest
        if q_dest:
            u = q_dest.popleft()
            if u in adj:
                for v in adj[u]:
                    if not vis_dest[v]:
                        vis_dest[v] = 1
                        parent_dest[v] = u
                        q_dest.append(v)

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
        adj = collections.defaultdict(list)
        for i in range(n):
            for j in range(n):
                val = int(next(it))
                if val == 1:
                    adj[i].append(j)

        src = int(next(it))
        dest = int(next(it))

        bidirectional_bfs(adj, src, dest, n)
    except (StopIteration, ValueError, EOFError):
        pass

if __name__ == "__main__":
    main()
