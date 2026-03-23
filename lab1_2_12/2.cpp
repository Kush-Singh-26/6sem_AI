#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cout << "Enter the string\n";
    cin >> str;
    reverse(str.begin(), str.end());

    cout << "Reversed string:\n" << str << "\n";
}