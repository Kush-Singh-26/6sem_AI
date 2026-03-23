#include<bits/stdc++.h>

using namespace std;

int main()
{
    int r1, c1, r2, c2;
    cout << "Enter row, col of mat 1 & mat 2 : ";
    cin >> r1 >> c1 >> r2 >> c2;
    if(c1 != c2 && r1 != r2)
    {
        cout << "Addition not possible\n";
        return 0;
    }
    cout << "Enter mat 1\n";
    vector<vector<int>> mat1(r1, vector<int>(c1,0));
    for(int i=0;i<r1;i++)
        for(int j=0;j<c1;j++)
            cin >> mat1[i][j];
    
    cout << "Enter mat 2\n";
    vector<vector<int>> mat2(r1, vector<int>(c1,0));
    for(int i=0;i<r1;i++)
        for(int j=0;j<c1;j++)
            cin >> mat2[i][j];           
    
    vector<vector<int>> mat3(r1, vector<int>(c1,0));
    for(int i = 0;i<r1;i++)
        for(int j = 0;j<c1;j++)
            mat3[i][j] = mat1[i][j] + mat2[i][j];

    cout << "Sum matrix\n";

    for(int i =0;i<r1;i++)
    {
        for(int j = 0;j<c1;j++)
            cout << mat3[i][j] << " ";
        cout << "\n";
    }
}