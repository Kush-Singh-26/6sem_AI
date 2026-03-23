#include<bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Enter 2 ints\n";
    int x,y;
    cin >> x >> y;

    x = x+y;
    y = x-y;
    x = x-y;

    cout << "After swapping : x = "<< x << " & y = " << y << "\n";
}