import sys

def is_safe(row, col, col_pos):
    for i in range(row):
        if col_pos[i] == col or abs(col_pos[i] - col) == abs(i - row):
            return False
    return True

def helper(n, col_pos, row, ans):
    if row == n:
        board = []
        for i in range(n):
            row_str = ["." for _ in range(n)]
            row_str[col_pos[i]] = "Q"
            board.append("".join(row_str))
        ans.append(board)
        return

    for col in range(n):
        if is_safe(row, col, col_pos):
            col_pos[row] = col
            helper(n, col_pos, row + 1, ans)

def n_queens(n):
    ans = []
    col_pos = [0] * n
    helper(n, col_pos, 0, ans)
    return ans

def main():
    try:
        n_input = input("Enter n : ")
        if not n_input:
            return
        n = int(n_input)
        
        ans = n_queens(n)

        if not ans:
            print(f"No solution exist for n = {n}")
        else:
            print(f"There exists {len(ans)} valid solutions : ")
            for solution in ans:
                for row in solution:
                    print(row)
                print("----------------------")
        
        print("23052247\nKush Singh\nCSE-22")
    except (ValueError, EOFError):
        pass

if __name__ == "__main__":
    main()
