/*
N-Queens
========

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]

Constraints:
1 <= n <= 9
*/

class Solution
{
public:
  bool isSafe(vector<vector<string>> &board, int r, int c)
  {
    int n = board.size();
    if (r < 0 || c < 0 || r >= n || c >= n)
      return false;

    // left side
    for (int i = 0; i <= c; ++i)
    {
      if (board[r][i] == "Q")
        return false;
    }

    // up side
    for (int i = 0; i <= r; ++i)
    {
      if (board[i][c] == "Q")
        return false;
    }

    // top left diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; j--, i--)
    {
      if (board[i][j] == "Q")
        return false;
    }

    // top right diagonal
    for (int i = r, j = c; i >= 0 && j < n; j++, i--)
    {
      if (board[i][j] == "Q")
        return false;
    }

    return true;
  }

  vector<string> convert(vector<vector<string>> &board)
  {
    vector<string> ans;
    for (auto &row : board)
    {
      string r;
      for (auto &c : row)
        r += c;
      ans.push_back(r);
    }
    return ans;
  }

  void solve(int n, vector<vector<string>> &board, int r, vector<vector<string>> &ans)
  {
    if (r == n)
    {
      ans.push_back(convert(board));
      return;
    }

    for (int c = 0; c < n; ++c)
    {
      if (isSafe(board, r, c))
      {
        board[r][c] = "Q";
        solve(n, board, r + 1, ans);
        board[r][c] = ".";
      }
    }
  }

  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> board(n, vector<string>(n, "."));
    vector<vector<string>> ans;
    solve(n, board, 0, ans);
    return ans;
  }
};
