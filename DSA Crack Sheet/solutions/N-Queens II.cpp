/*
N-Queens II
===========

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:
Input: n = 1
Output: 1

Constraints:
1 <= n <= 9
*/

class Solution
{
public:
  bool isSafe(vector<vector<int>> &board, int r, int c)
  {
    int n = board.size();
    if (r < 0 || c < 0 || r >= n || c >= n)
      return false;

    // left side
    for (int i = 0; i <= c; ++i)
    {
      if (board[r][i] == 1)
        return false;
    }

    // up side
    for (int i = 0; i <= r; ++i)
    {
      if (board[i][c] == 1)
        return false;
    }

    // top left diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; j--, i--)
    {
      if (board[i][j] == 1)
        return false;
    }

    // top right diagonal
    for (int i = r, j = c; i >= 0 && j < n; j++, i--)
    {
      if (board[i][j] == 1)
        return false;
    }

    return true;
  }

  void solve(int n, vector<vector<int>> &board, int r, int &ans)
  {
    if (r == n)
    {
      ans++;
      return;
    }

    for (int c = 0; c < n; ++c)
    {
      if (isSafe(board, r, c))
      {
        board[r][c] = 1;
        solve(n, board, r + 1, ans);
        board[r][c] = 0;
      }
    }
  }

  int totalNQueens(int n)
  {
    int ans = 0;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(n, board, 0, ans);
    return ans;
  }
};
