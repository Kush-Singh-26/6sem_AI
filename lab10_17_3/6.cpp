#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    string start = "123405786"; // 0 represents the empty space
    string target = "123456780"; // The goal state
    
    queue<string> q;
    unordered_map<string, int> moves; // Stores visited board states and moves taken
    
    q.push(start);
    moves[start] = 0;
    
    // Direction vectors: Up, Down, Left, Right
    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}; 
    
    while (!q.empty()) {
        string curr = q.front(); 
        q.pop();
        
        // Base Case: We found the target!
        if (curr == target) {
            cout << "Solved in " << moves[curr] << " moves!\n";
            return 0;
        }
        
        // Find the empty space ('0') and convert its 1D index to 2D (row, col)
        int zero = curr.find('0'); 
        int x = zero / 3, y = zero % 3; 
        
        // Try sliding adjacent tiles into the empty space
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i]; // New row and column
            
            // Check if the move is strictly inside the 3x3 grid
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) { 
                string next_state = curr;
                swap(next_state[zero], next_state[nx * 3 + ny]); // Execute the slide
                
                // If we've never seen this exact board layout before, queue it up
                if (!moves.count(next_state)) { 
                    moves[next_state] = moves[curr] + 1;
                    q.push(next_state);
                }
            }
        }
    }
    
    cout << "Unsolvable puzzle.\n"; 
    return 0;
}