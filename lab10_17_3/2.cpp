#include<bits/stdc++.h>

using namespace std;

int fitness(string s){
    int score = 0;
    for(int i= 0;i<5;i++)
        score += (s[i] == "HELLO"[i]);
    return score;
}

int main(){
    int c = 1;
    vector<string> pop(20, "AAAAA");
    
    while(fitness(pop[0])<5){
        // Selection 
        sort(pop.begin(), pop.end(), [](string a, string b){return fitness(a) > fitness(b); });
        
        // crossover & mutation
        // replace the bottom half with children of top half
        for(int i =10;i<20;i++){
            string p1 = pop[rand() % 10], p2 = pop[rand() % 10];
            for(int j = 0;j<5;j++)
                // take 2 random str from pop and 50/50 chance of selecting a char from each
                pop[i][j] = (rand() % 2 ? p1[j] : p2[j]);
            if(rand() % 10 < 2)         // 20% chance to mutate a letter 
                pop[i][rand() % 5] = 'A' + rand() % 26;
        }
        cout << c << ". Best so far : " << pop[0] << "\n";
        c++;
    }
    return 0;
}