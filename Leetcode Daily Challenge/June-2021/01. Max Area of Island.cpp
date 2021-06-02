/*
Max Area of Island
==================

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

class Solution
{
public:
  int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int bfs(vector<vector<int>> &grid, int r, int c)
  {
    int ans = 0;
    int n = grid.size(), m = grid[0].size();
    queue<int> q;
    q.push(r * m + c);
    grid[r][c] = 0;

    while (q.size())
    {
      for (auto i = q.size(); i > 0; --i)
      {
        int x = q.front() / m, y = q.front() % m;
        q.pop();
        ans++;

        for (auto &dir : dirs)
        {
          int nx = x + dir[0], ny = y + dir[1];
          if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny])
          {
            grid[nx][ny] = 0;
            q.push(nx * m + ny);
          }
        }
      }
    }
    return ans;
  }

  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
      for (int j = 0; j < grid[0].size(); ++j)
      {
        if (grid[i][j])
          ans = max(ans, bfs(grid, i, j));
      }
    }

    return ans;
  }
};
