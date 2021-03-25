/*
Pacific Atlantic Water Flow
===========================

Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.

Example:
Given the following 5x5 matrix:
  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:
[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/

class Solution
{
public:
  bool valid(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &visited)
  {
    return (i >= 0 && j >= 0 && i < matrix.size() && j < matrix[0].size() && !visited[i][j]);
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
  {
    if (matrix.size() == 0 || matrix[0].size() == 0)
      return {};
    int n = matrix.size(), m = matrix[0].size();

    vector<vector<int>> pacific(n, vector<int>(m, 0)), atlantic(n, vector<int>(m, 0));
    vector<vector<int>> ans;

    vector<int> dirs = {-1, 0, 1, 0, -1};

    queue<vector<int>> pending;
    pending.push({0, 0});
    pacific[0][0] = 1;

    while (pending.size())
    {
      auto curr = pending.front();
      pending.pop();
      int x = curr[0], y = curr[1];

      for (int i = 0; i < 4; ++i)
      {
        int nextX = x + dirs[i], nextY = y + dirs[i + 1];
        if (valid(nextX, nextY, matrix, pacific))
        {
          if (nextX == 0 || nextY == 0 || matrix[nextX][nextY] >= matrix[x][y])
          {
            pending.push({nextX, nextY});
            pacific[nextX][nextY] = 1;
            continue;
          }
        }
      }
    }

    pending.push({n - 1, m - 1});
    atlantic[n - 1][m - 1] = 1;

    while (pending.size())
    {
      auto curr = pending.front();
      pending.pop();
      int x = curr[0], y = curr[1];

      for (int i = 0; i < 4; ++i)
      {
        int nextX = x + dirs[i], nextY = y + dirs[i + 1];
        if (valid(nextX, nextY, matrix, atlantic))
        {
          if (nextX == n - 1 || nextY == m - 1 || matrix[nextX][nextY] >= matrix[x][y])
          {
            pending.push({nextX, nextY});
            atlantic[nextX][nextY] = 1;
            continue;
          }
        }
      }
    }

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (pacific[i][j] && atlantic[i][j])
          ans.push_back({i, j});
      }
    }

    return ans;
  }
};
