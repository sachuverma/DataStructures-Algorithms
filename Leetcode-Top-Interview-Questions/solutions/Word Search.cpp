/*
Word Search
===========

Given an m x n board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.


Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 200
1 <= word.length <= 103
board and word consists only of lowercase and uppercase English letters.
*/

class Solution
{
  bool exist(vector<vector<char>> &board, vector<vector<int>> &visited, int r, int c, string word, int i)
  {
    if (i == word.size())
      return true;
    if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || i > word.size() || board[r][c] != word[i] || visited[r][c])
      return false;

    visited[r][c] = 1;
    bool ans = false;

    ans = ans || exist(board, visited, r + 1, c, word, i + 1) || exist(board, visited, r - 1, c, word, i + 1) || exist(board, visited, r, c + 1, word, i + 1) || exist(board, visited, r, c - 1, word, i + 1);

    visited[r][c] = 0;
    return ans;
  }

public:
  bool exist(vector<vector<char>> &board, string word)
  {
    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
    for (int i = 0; i < board.size(); ++i)
    {
      for (int j = 0; j < board[0].size(); ++j)
      {
        if (board[i][j] == word[0] && exist(board, visited, i, j, word, 0))
          return true;
      }
    }

    return false;
  }
};
