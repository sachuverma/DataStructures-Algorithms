/*
Game of Life
============

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

Example 1:
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

Example 2:
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]

Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.

Follow up:
Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

*/

class Solution
{
public:
  int maxX, maxY;
  int checkNeighbours(vector<vector<int>> &board, int x, int y)
  {
    // support variables
    int res = -board[y][x];
    // checking the neighbours
    for (int cy = max(0, y - 1), lmtY = min(maxY, y + 2); cy < lmtY; cy++)
    {
      for (int cx = max(0, x - 1), lmtX = min(maxX, x + 2); cx < lmtX; cx++)
        res += board[cy][cx];
    }
    return res;
  }
  void gameOfLife(vector<vector<int>> &board)
  {
    // updating class variables
    maxY = board.size(), maxX = board[0].size();
    // support variables
    vector<vector<int>> newBoard(maxY);
    // commputing newBoard
    for (int y = 0; y < maxY; y++)
    {
      newBoard[y] = vector<int>(maxX);
      for (int x = 0, currCell, currNeighbours; x < maxX; x++)
      {
        currCell = board[y][x];
        currNeighbours = checkNeighbours(board, x, y);
        newBoard[y][x] = !currCell && currNeighbours == 3 ||
                         currCell && currNeighbours > 1 && currNeighbours < 4;
      }
    }
    // updating board
    board = newBoard;
  }
};
