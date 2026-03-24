#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int checkWin(const string& b) {
    int wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for (auto w : wins) {
        if (b[w[0]] != ' ' && b[w[0]] == b[w[1]] && b[w[1]] == b[w[2]])
            return (b[w[0]] == 'X') ? 10 : -10;
    }
    return 0;
}

// Added alpha (-infinity) and beta (+infinity) parameters
int minimax(string& b, int depth, bool isMax, int alpha, int beta) {
    int score = checkWin(b);
    if (score == 10) return score - depth;
    if (score == -10) return score + depth;
    if (b.find(' ') == string::npos) return 0;

    int best = isMax ? -1000 : 1000;
    for (int i = 0; i < 9; i++) {
        if (b[i] == ' ') {
            b[i] = isMax ? 'X' : 'O';
            int val = minimax(b, depth + 1, !isMax, alpha, beta);
            b[i] = ' '; // Backtrack

            // Alpha-Beta Pruning Logic
            if (isMax) {
                best = max(best, val);
                alpha = max(alpha, best); // Update the Maximizer's best guarantee
            } else {
                best = min(best, val);
                beta = min(beta, best);   // Update the Minimizer's best guarantee
            }

            if (beta <= alpha) break; // PRUNE! The opponent won't let us go down this path
        }
    }
    return best;
}

int main() {
    string b = "         ";
    cout << "You are 'X'. Enter 0-8 to move.\n";

    while (checkWin(b) == 0 && b.find(' ') != string::npos) {
        int move;
        cout << "\nYour move: ";
        cin >> move;
        if (move < 0 || move > 8 || b[move] != ' ') continue;
        b[move] = 'X';

        if (checkWin(b) == 0 && b.find(' ') != string::npos) {
            int bestScore = 1000, bestMove = -1;
            for (int i = 0; i < 9; i++) {
                if (b[i] == ' ') {
                    b[i] = 'O';
                    // Initial call passes -1000 for alpha and 1000 for beta
                    int score = minimax(b, 0, true, -1000, 1000); 
                    if (score < bestScore) { bestScore = score; bestMove = i; }
                    b[i] = ' ';
                }
            }
            b[bestMove] = 'O';
        }

        for (int i = 0; i < 9; i++) {
            cout << " " << b[i] << " " << ((i + 1) % 3 == 0 ? "\n" : "|");
            if (i == 2 || i == 5) cout << "---+---+---\n";
        }
    }

    int res = checkWin(b);
    cout << "\n" << (res == 10 ? "You win!" : res == -10 ? "AI wins!" : "Draw!") << "\n";
    return 0;
}