/*
Valid Sudoku
============

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Example 1:
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


Constraints:
board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
*/
class Solution
{
  bool isCorrect(vector<vector<char>> &board, char elem, int r, int c)
  {
    int rows = board.size(), cols = board[0].size();
    int smallBR = 0, smallBC = 0;

    for (int i = 0; i < rows; ++i)
      if (i != r && elem == board[i][c])
        return false;
    for (int i = 0; i < cols; ++i)
      if (i != c && elem == board[r][i])
        return false;

    if (r < 3)
      smallBR = 0;
    else if (r < 6)
      smallBR = 3;
    else if (r < 9)
      smallBR = 6;

    if (c < 3)
      smallBC = 0;
    else if (c < 6)
      smallBC = 3;
    else if (c < 9)
      smallBC = 6;

    for (int i = smallBR; i < smallBR + 3; ++i)
    {
      for (int j = smallBC; j < smallBC + 3; ++j)
      {
        if (i == r && j == c)
          continue;
        else if (elem == board[i][j])
          return false;
      }
    }
    return true;
  }

public:
  bool isValidSudoku(vector<vector<char>> &board)
  {
    for (int i = 0; i < board.size(); ++i)
    {
      for (int j = 0; j < board[0].size(); ++j)
      {
        if (board[i][j] != '.')
          if (!isCorrect(board, board[i][j], i, j))
            return false;
      }
    }
    return true;
  }
};
