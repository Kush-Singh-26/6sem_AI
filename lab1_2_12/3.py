import sys

def main():
    try:
        line = input("Enter row, col of mat 1 & mat 2 : ").split()
        if not line: return
        r1, c1, r2, c2 = map(int, line)
        
        if c1 != c2 or r1 != r2:
            print("Addition not possible")
            return

        print("Enter mat 1")
        mat1 = []
        for _ in range(r1):
            mat1.append(list(map(int, input().split())))
        
        print("Enter mat 2")
        mat2 = []
        for _ in range(r1):
            mat2.append(list(map(int, input().split())))
            
        mat3 = [[0 for _ in range(c1)] for _ in range(r1)]
        for i in range(r1):
            for j in range(c1):
                mat3[i][j] = mat1[i][j] + mat2[i][j]

        print("Sum matrix")
        for row in mat3:
            print(*(row))
            
    except (ValueError, EOFError, IndexError):
        pass

if __name__ == "__main__":
    main()
