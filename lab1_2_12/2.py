def main():
    try:
        s = input("Enter the string\n")
        # In Python, string reversal is easy
        reversed_str = s[::-1]
        print(f"Reversed string:\n{reversed_str}")
    except (EOFError):
        pass

if __name__ == "__main__":
    main()
