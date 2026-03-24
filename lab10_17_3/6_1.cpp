#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <cmath>

using namespace std;

const string TARGET = "123456780"; // The goal state

// Calculates Manhattan Distance: How far is each tile from its home?
int getHeuristic(const string& board) {
    int dist = 0;
    for (int i = 0; i < 9; i++) {
        if (board[i] == '0') continue; // Ignore the empty space
        
        int val = board[i] - '1'; // '1' belongs at index 0, '2' at 1, etc.
        
        // Current 2D coordinates
        int currX = i / 3, currY = i % 3;
        // Target 2D coordinates
        int targetX = val / 3, targetY = val % 3;
        
        dist += abs(currX - targetX) + abs(currY - targetY);
    }
    return dist;
}

// A simple struct to hold our state and sort by lowest total cost
struct State {
    string board;
    int moves; // g(n)
    int cost;  // f(n) = g(n) + h(n)
    
    // The priority queue puts the lowest cost at the top
    bool operator>(const State& other) const {
        return cost > other.cost; 
    }
};

int main() {
    string start = "123405786"; 
    
    // Priority queue to always explore the most promising paths first
    priority_queue<State, vector<State>, greater<State>> pq;
    unordered_map<string, int> best_moves; 
    
    pq.push({start, 0, getHeuristic(start)});
    best_moves[start] = 0;
    
    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}; 
    
    while (!pq.empty()) {
        State curr = pq.top(); 
        pq.pop();
        
        // Base Case: We found the target!
        if (curr.board == TARGET) {
            cout << "Solved in " << curr.moves << " moves!\n";
            return 0;
        }
        
        // If we previously found a faster way to reach this exact board, skip it
        if (curr.moves > best_moves[curr.board]) continue;
        
        int zero = curr.board.find('0'); 
        int x = zero / 3, y = zero % 3; 
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i]; 
            
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) { 
                string next_state = curr.board;
                swap(next_state[zero], next_state[nx * 3 + ny]); 
                
                int next_moves = curr.moves + 1;
                
                // If we've never seen this board, or we found a shorter path to it
                if (!best_moves.count(next_state) || next_moves < best_moves[next_state]) { 
                    best_moves[next_state] = next_moves;
                    
                    // f(n) = g(n) + h(n)
                    int priority = next_moves + getHeuristic(next_state); 
                    pq.push({next_state, next_moves, priority});
                }
            }
        }
    }
    
    cout << "Unsolvable puzzle.\n"; 
    return 0;
}