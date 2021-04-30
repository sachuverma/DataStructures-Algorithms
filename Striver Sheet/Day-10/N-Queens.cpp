/*
N-Queens
========

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
    for (int i = 0; i < n; ++i)
    {
      if (board[r][i] == 1)
        return false;
      if (board[i][c] == 1)
        return false;
    }

    for (int i = r, j = c; i >= 0 && j >= 0; --i, --j)
    {
      if (board[i][j] == 1)
        return false;
    }

    for (int i = r, j = c; i >= 0 && j < n; --i, ++j)
    {
      if (board[i][j] == 1)
        return false;
    }
    return true;
  }

  void nQueen(vector<vector<int>> &board, int r, int &ans)
  {
    int n = board.size();
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
        nQueen(board, r + 1, ans);
        board[r][c] = 0;
      }
    }
  }

  int totalNQueens(int n)
  {
    int ans = 0;
    vector<vector<int>> board(n, vector<int>(n, 0));
    nQueen(board, 0, ans);
    return ans;
  }
};
