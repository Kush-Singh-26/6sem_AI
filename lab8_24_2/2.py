def f(a, b, c, x):
    return a * x * x + b * x + c

def hill_climb(a, b, c, start, step):
    current = start
    history = [current]

    while True:
        left_neighbor = current - step
        right_neighbor = current + step

        # Find the neighbor with the higher value (Maximizing)
        if f(a, b, c, left_neighbor) > f(a, b, c, right_neighbor):
            next_point = left_neighbor
        else:
            next_point = right_neighbor

        # If next point is not better than current, we've reached a peak
        if f(a, b, c, next_point) <= f(a, b, c, current):
            break
        
        current = next_point
        history.append(current)

    print(f"Final Path: {history}")

def main():
    try:
        a = float(input("Enter coefficient a: "))
        b = float(input("Enter coefficient b: "))
        c = float(input("Enter coefficient c: "))
        start = float(input("Enter starting point: "))
        step = float(input("Enter step size: "))

        hill_climb(a, b, c, start, step)
        print("23052247\nKush Singh\nCSE-22")
    except (ValueError, EOFError):
        pass

if __name__ == "__main__":
    main()
