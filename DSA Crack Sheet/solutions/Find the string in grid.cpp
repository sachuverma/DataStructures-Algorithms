/*
Find the string in grid
=======================

Given a 2D grid (G[]) of characters and a word(x), find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said be found in a direction if all characters match in this direction (not in zig-zag form).

The 8 directions are, Horizontally Left, Horizontally Right, Vertically Up, Vertically down and 4 Diagonal directions.

Example:
Input:  G[][] = {"GEEKSFORGEEKS",
                 "GEEKSQUIZGEEK",
                 "IDEQAPRACTICE"};
        x = "GEEKS"

Output: pattern found at 0, 0
        pattern found at 0, 8
        pattern found at 1, 0

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow.  Each test case contains two space separated integers N and M denoting the size of the grid. Then in the next line are N * M space separated values of the grid. In the next line is the word x.

Output:
For each test case in a new line print the space separated sorted indexes of the matrix where after each index there is a ', ' . If there are no such occurences print -1.

Constraints:
1<=T<100
1<=N,M<=100
1<=G[]<=100

Example:
Input:
2
3 3
a b c d e f g h i
abc
4 3
a b a b a b e b e b e b
abe
Output:
0 0,
0 0, 0 2, 1 1,
*/

#include <bits/stdc++.h>
using namespace std;

bool search2D(vector<vector<char>> &grid, int i, int j, string word)
{
  if (grid[i][j] != word[0])
    return false;

  int len = word.size(), n = grid.size(), m = grid[0].size();

  // For searching in all 8 direction
  int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int dir = 0; dir < 8; dir++)
  {
    int k, rd = i + x[dir], cd = j + y[dir];
    for (k = 1; k < len; k++)
    {
      if (rd >= n || rd < 0 || cd >= m || cd < 0)
        break;
      if (grid[rd][cd] != word[k])
        break;
      rd += x[dir];
      cd += y[dir];
    }
    if (k == len)
      return true;
  }
  return false;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m, '0'));
  for (auto &row : grid)
  {
    for (auto &elem : row)
      cin >> elem;
  }
  int flag = 1;
  string word;
  cin >> word;

  for (int row = 0; row < n; row++)
  {
    for (int col = 0; col < m; col++)
    {
      if (search2D(grid, row, col, word))
      {
        cout << row << " " << col << ", ";
        flag = 0;
      }
    }
  }
  if (flag)
    cout << -1;
  cout << endl;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
