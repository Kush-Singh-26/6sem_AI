#include <bits/stdc++.h>

using namespace std;

bool isSafe(int row, int col, vector<int> &col_pos) {
  for (int i = 0; i < row; i++) {
    if (col_pos[i] == col || abs(col_pos[i] - col) == abs(i - row))
      return false;
  }
  return true;
}

void helper(int n, vector<int> &col_pos, int row, vector<vector<string>> &ans) {
  if (n == row) {
    vector<string> temp(n, string(n, '.'));
    for (int i = 0; i < n; i++)
      temp[i][col_pos[i]] = 'Q';
    ans.push_back(temp);
    return;
  }
  for (int col = 0; col < n; col++) {
    if (isSafe(row, col, col_pos)) {
      col_pos[row] = col;
      helper(n, col_pos, row + 1, ans);
    }
  }
}

vector<vector<string>> NQueens(int n) {
  vector<vector<string>> ans;
  vector<int> col_pos(n);
  helper(n, col_pos, 0, ans);
  return ans;
}

int main() {
  cout << "Enter n : ";
  int n;
  cin >> n;
  vector<vector<string>> ans = NQueens(n);

  if (ans.empty())
    cout << "No solution exist for n = " << n << "\n";
  else {
    cout << "There exists " << ans.size() << " valid solutions : \n";
    for (int i = 0; i < ans.size(); i++) {
      for (int j = 0; j < ans[i].size(); j++)
        cout << ans[i][j] << "\n";
      cout << "----------------------\n";
    }
  }
  cout << "23052247\nKush Singh\nCSE-22\n";
  return 0;
}
/*
 Output :
 Enter n : 4
 There exists 2 valid solutions :
 .Q..
 ...Q
 Q...
 ..Q.
 ----------------------
 ..Q.
 Q...
 ...Q
 .Q..
 ----------------------
 23052247
 Kush Singh
 CSE-22
 */
