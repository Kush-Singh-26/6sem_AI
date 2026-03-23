import sys

# --- State and Move Definitions ---

class GameState:
    def __init__(self, board, currentPlayer):
        self.board = board
        self.currentPlayer = currentPlayer

class Move:
    def __init__(self, index):
        self.index = index

# --- Helper Functions ---

# Prints the board to the console
def printBoard(state):
    print()
    for i in range(9):
        print(f" {state.board[i]} ", end="")
        if (i + 1) % 3 == 0:
            print()
        else:
            print("|", end="")
        if i == 2 or i == 5:
            print("---+---+---")
    print()

# Returns a list of all empty spots
def getPossibleMoves(state):
    moves = []
    for i in range(9):
        if state.board[i] == ' ':
            moves.append(Move(i))
    return moves

# Creates a new board state based on the chosen move
def applyMove(state, move):
    new_board = list(state.board)
    new_board[move.index] = state.currentPlayer
    next_player = 'O' if state.currentPlayer == 'X' else 'X'
    return GameState(new_board, next_player)

# Evaluates the board. Returns +10 if X wins, -10 if O wins, 0 otherwise.
def evaluate(state):
    b = state.board
    winLines = [
        (0, 1, 2), (3, 4, 5), (6, 7, 8), # Rows
        (0, 3, 6), (1, 4, 7), (2, 5, 8), # Cols
        (0, 4, 8), (2, 4, 6)             # Diagonals
    ]

    for line in winLines:
        if b[line[0]] != ' ' and b[line[0]] == b[line[1]] == b[line[2]]:
            return 10 if b[line[0]] == 'X' else -10
    return 0

# Checks if the game is over (win, loss, or draw)
def isGameOver(state):
    if evaluate(state) != 0:
        return True
    for cell in state.board:
        if cell == ' ':
            return False
    return True

# --- The Minimax Algorithm ---
# depth counts up to penalize slower wins
def minimax(state, depth, isMaximizingPlayer):
    score = evaluate(state)

    # Base Cases: Win, Loss, or Draw
    if score == 10:
        return score - depth  # Favor faster wins for X
    if score == -10:
        return score + depth  # Favor faster wins for O
    
    possible_moves = getPossibleMoves(state)
    if not possible_moves:
        return 0  # Draw

    if isMaximizingPlayer:
        bestScore = -float('inf')
        for currentMove in possible_moves:
            nextState = applyMove(state, currentMove)
            bestScore = max(bestScore, minimax(nextState, depth + 1, False))
        return bestScore
    else:
        bestScore = float('inf')
        for currentMove in possible_moves:
            nextState = applyMove(state, currentMove)
            bestScore = min(bestScore, minimax(nextState, depth + 1, True))
        return bestScore

# Finds the best move for the AI
def findBestMove(currentState):
    bestScore = float('inf')  # AI plays as 'O', so it is the Minimizer
    bestMove = Move(-1)

    for currentMove in getPossibleMoves(currentState):
        nextState = applyMove(currentState, currentMove)
        moveScore = minimax(nextState, 0, True)  # Next turn is 'X' (Maximizer)
        
        # Since AI is 'O', it wants the lowest possible score
        if moveScore < bestScore:
            bestScore = moveScore
            bestMove = currentMove
            
    return bestMove

# --- Main Game Loop ---
def main():
    # Initialize empty board. User is 'X', AI is 'O'.
    game = GameState([' '] * 9, 'X')
    
    print("Welcome to Tic-Tac-Toe vs Minimax AI!")
    print("You are 'X'. Enter a number 0-8 to make your move.")
    print(" 0 | 1 | 2 \n---+---+---\n 3 | 4 | 5 \n---+---+---\n 6 | 7 | 8 ")

    while not isGameOver(game):
        if game.currentPlayer == 'X':
            # Human Turn
            try:
                line = input("\nYour turn (0-8): ")
                if not line:
                    continue
                userInput = int(line)

                if userInput < 0 or userInput > 8 or game.board[userInput] != ' ':
                    print("Invalid move. Try again.")
                    continue
                game = applyMove(game, Move(userInput))
            except (ValueError, IndexError):
                print("Invalid input. Please enter a number between 0 and 8.")
                continue
        else:
            # AI Turn
            print("\nAI is thinking...")
            aiMove = findBestMove(game)
            game = applyMove(game, aiMove)
            print(f"AI placed 'O' at position {aiMove.index}.")
        
        printBoard(game)

    # Announce Winner
    finalScore = evaluate(game)
    if finalScore == 10:
        print("You win! (Wait, this shouldn't be possible...)")
    elif finalScore == -10:
        print("AI wins! Better luck next time.")
    else:
        print("It's a draw!")

if __name__ == "__main__":
    main()
