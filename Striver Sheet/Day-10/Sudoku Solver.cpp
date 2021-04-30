/*
Sudoku Solver
=============

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Example 1:
Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:

Constraints:
board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
*/

class Solution
{
public:
  bool isSafe(vector<vector<char>> &board, int r, int c, char val)
  {
    for (int i = 0; i < 9; ++i)
    {
      if (board[i][c] == val || board[r][i] == val)
        return false;
    }

    int si = 3 * (r / 3), sj = 3 * (c / 3);
    for (int i = 0; i < 3; ++i)
    {
      for (int j = 0; j < 3; ++j)
      {
        if (board[i + si][j + sj] == val)
          return false;
      }
    }

    return true;
  }

  bool helper(vector<vector<char>> &board, int r, int c)
  {
    if (c == 9)
    {
      r++;
      c = 0;
    }
    if (r == 9)
      return true;
    if (board[r][c] != '.')
      return helper(board, r, c + 1);

    for (char ch = '1'; ch <= '9'; ++ch)
    {
      if (isSafe(board, r, c, ch))
      {
        board[r][c] = ch;
        if (helper(board, r, c + 1))
          return true;
        board[r][c] = '.';
      }
    }
    return false;
  }

  void solveSudoku(vector<vector<char>> &board)
  {
    helper(board, 0, 0);
  }
};