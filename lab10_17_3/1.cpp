#include<bits/stdc++.h>

using namespace std;

// --- State and Move Definitions ---
struct GameState {
    vector<char> board;
    char currentPlayer;
};

struct Move {
    int index;
};

// --- Helper Functions ---

// Prints the board to the console
void printBoard(const GameState& state) {
    cout << "\n";
    for (int i = 0; i < 9; ++i) {
        cout << " " << state.board[i] << " ";
        if ((i + 1) % 3 == 0) cout << "\n";
        else cout << "|";
        if (i == 2 || i == 5) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Returns a list of all empty spots
vector<Move> getPossibleMoves(const GameState& state) {
    vector<Move> moves;
    for (int i = 0; i < 9; ++i) {
        if (state.board[i] == ' ') {
            moves.push_back({i});
        }
    }
    return moves;
}

// Creates a new board state based on the chosen move
GameState applyMove(const GameState& state, Move move) {
    GameState nextState = state;
    nextState.board[move.index] = state.currentPlayer;
    nextState.currentPlayer = (state.currentPlayer == 'X') ? 'O' : 'X';
    return nextState;
}

// Evaluates the board. Returns +10 if X wins, -10 if O wins, 0 otherwise.
int evaluate(const GameState& state) {
    const auto& b = state.board;
    int winLines[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Cols
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (int i = 0; i < 8; ++i) {
        if (b[winLines[i][0]] != ' ' &&
            b[winLines[i][0]] == b[winLines[i][1]] && 
            b[winLines[i][1]] == b[winLines[i][2]]) {
            return (b[winLines[i][0]] == 'X') ? 10 : -10;
        }
    }
    return 0;
}

// Checks if the game is over (win, loss, or draw)
bool isGameOver(const GameState& state) {
    if (evaluate(state) != 0) return true;
    for (char cell : state.board) {
        if (cell == ' ') return false;
    }
    return true;
}

// --- The Minimax Algorithm ---
// depth counts up to penalize slower wins
int minimax(GameState state, int depth, bool isMaximizingPlayer) {
    int score = evaluate(state);

    // Base Cases: Win, Loss, or Draw
    if (score == 10) return score - depth; // Favor faster wins for X
    if (score == -10) return score + depth; // Favor faster wins for O
    if (getPossibleMoves(state).empty()) return 0; // Draw

    if (isMaximizingPlayer) {
        int bestScore = INT_MIN;
        for (Move currentMove : getPossibleMoves(state)) {
            GameState nextState = applyMove(state, currentMove);
            bestScore = max(bestScore, minimax(nextState, depth + 1, false));
        }
        return bestScore;
    } else {
        int bestScore = INT_MAX;
        for (Move currentMove : getPossibleMoves(state)) {
            GameState nextState = applyMove(state, currentMove);
            bestScore = min(bestScore, minimax(nextState, depth + 1, true));
        }
        return bestScore;
    }
}

// Finds the best move for the AI
Move findBestMove(GameState currentState) {
    int bestScore = INT_MAX; // AI plays as 'O', so it is the Minimizer
    Move bestMove = {-1};

    for (Move currentMove : getPossibleMoves(currentState)) {
        GameState nextState = applyMove(currentState, currentMove);
        int moveScore = minimax(nextState, 0, true); // Next turn is 'X' (Maximizer)
        
        // Since AI is 'O', it wants the lowest possible score
        if (moveScore < bestScore) {
            bestScore = moveScore;
            bestMove = currentMove;
        }
    }
    return bestMove;
}

// --- Main Game Loop ---
int main() {
    // Initialize empty board. User is 'X', AI is 'O'.
    GameState game = {vector<char>(9, ' '), 'X'};
    
    cout << "Welcome to Tic-Tac-Toe vs Minimax AI!\n";
    cout << "You are 'X'. Enter a number 0-8 to make your move.\n";
    cout << " 0 | 1 | 2 \n---+---+---\n 3 | 4 | 5 \n---+---+---\n 6 | 7 | 8 \n";

    while (!isGameOver(game)) {
        if (game.currentPlayer == 'X') {
            // Human Turn
            int userInput;
            cout << "\nYour turn (0-8): ";
            cin >> userInput;

            if (userInput < 0 || userInput > 8 || game.board[userInput] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }
            game = applyMove(game, {userInput});
        } else {
            // AI Turn
            cout << "\nAI is thinking...\n";
            Move aiMove = findBestMove(game);
            game = applyMove(game, aiMove);
            cout << "AI placed 'O' at position " << aiMove.index << ".\n";
        }
        printBoard(game);
    }

    // Announce Winner
    int finalScore = evaluate(game);
    if (finalScore == 10) cout << "You win! (Wait, this shouldn't be possible...)\n";
    else if (finalScore == -10) cout << "AI wins! Better luck next time.\n";
    else cout << "It's a draw!\n";

    return 0;
}