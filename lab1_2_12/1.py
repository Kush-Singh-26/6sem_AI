def main():
    print("Enter 2 ints")
    try:
        line = input().split()
        if len(line) < 2:
            return
        x = int(line[0])
        y = int(line[1])

        # Swapping logic using arithmetic
        x = x + y
        y = x - y
        x = x - y

        print(f"After swapping : x = {x} & y = {y}")
    except (ValueError, EOFError):
        pass

if __name__ == "__main__":
    main()
