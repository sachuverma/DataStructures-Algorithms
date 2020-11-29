/*
Number of Islands
=================

Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3


Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

class Solution
{
  void bfs(vector<vector<char>> &grid, int i, int j)
  {
    if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
      return;
    grid[i][j] = '0';
    bfs(grid, i + 1, j);
    bfs(grid, i - 1, j);
    bfs(grid, i, j + 1);
    bfs(grid, i, j - 1);
  }

public:
  int numIslands(vector<vector<char>> &grid)
  {
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
      for (int j = 0; j < grid[0].size(); ++j)
      {
        if (grid[i][j] == '1')
        {
          ans++;
          bfs(grid, i, j);
        }
      }
    }
    return ans;
  }
};
