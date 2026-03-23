import collections

def water_jug(jug1_cap, jug2_cap, target):
    # Standard BFS for Water Jug problem with 2 jugs
    queue = collections.deque([(0, 0)])
    visited = set([(0, 0)])
    parent = {}

    goal = None

    while queue:
        state = queue.popleft()
        a, b = state

        if a == target or b == target:
            goal = state
            break

        # Possible moves
        next_states = [
            (jug1_cap, b),  # Fill Jug 1
            (a, jug2_cap),  # Fill Jug 2
            (0, b),         # Empty Jug 1
            (a, 0),         # Empty Jug 2
            # Pour Jug 1 to Jug 2
            (a - min(a, jug2_cap - b), b + min(a, jug2_cap - b)),
            # Pour Jug 2 to Jug 1
            (a + min(b, jug1_cap - a), b - min(b, jug1_cap - a))
        ]

        for nxt in next_states:
            if nxt not in visited:
                visited.add(nxt)
                parent[nxt] = state
                queue.append(nxt)

    if goal is None:
        print("No solution possible.")
        return

    # Reconstruct path
    path = []
    curr = goal
    while curr != (0, 0):
        path.append(curr)
        curr = parent[curr]
    path.append((0, 0))
    path.reverse()

    print("Solution Path:")
    for p in path:
        print(f"({p[0]}, {p[1]})")

def main():
    try:
        jug1 = int(input("Enter Jug1 Capacity: "))
        jug2 = int(input("Enter Jug2 Capacity: "))
        target = int(input("Enter Target Amount: "))
        
        water_jug(jug1, jug2, target)
        print("23052247\nKush Singh\nCSE-22")
    except (ValueError, EOFError):
        pass

if __name__ == "__main__":
    main()
