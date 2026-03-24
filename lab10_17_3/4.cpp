#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string d = "0123456789"; // The pool of available digits

    do {
        // Map the first 8 digits of the current permutation to S,E,N,D,M,O,R,Y
        int S=d[0]-'0', E=d[1]-'0', N=d[2]-'0', D=d[3]-'0', M=d[4]-'0', O=d[5]-'0', R=d[6]-'0', Y=d[7]-'0';
        
        if (S == 0 || M == 0) continue; // Constraint: No leading zeros

        // Build the integers
        int send  = S*1000 + E*100 + N*10 + D;
        int more  = M*1000 + O*100 + R*10 + E;
        int money = M*10000 + O*1000 + N*100 + E*10 + Y;

        // Constraint: The math must work
        if (send + more == money) {
            cout << send << " + " << more << " = " << money << "\n";
            break; // Stop after finding the first valid answer
        }
    } while (next_permutation(d.begin(), d.end())); // Generates the next unique combination
}