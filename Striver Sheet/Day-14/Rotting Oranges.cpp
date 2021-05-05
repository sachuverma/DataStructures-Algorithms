/*
Rotting Oranges
===============

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

class Solution
{
public:
  int dirs[4][4] = {
      {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  int orangesRotting(vector<vector<int>> &grid)
  {
    queue<vector<int>> q;
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
      for (int j = 0; j < grid[0].size(); ++j)
      {
        if (grid[i][j] == 2)
        {
          q.push({i, j, 0});
        }
      }
    }

    while (q.size())
    {
      auto curr = q.front();
      q.pop();
      int i = curr[0], j = curr[1], time = curr[2];
      ans = max(ans, time);
      for (auto &d : dirs)
      {
        int nextI = i + d[0], nextJ = j + d[1];
        if (nextI >= 0 && nextJ >= 0 && nextI < grid.size() && nextJ < grid[0].size())
        {
          if (grid[nextI][nextJ] == 1)
          {
            grid[nextI][nextJ] = 2;
            q.push({nextI, nextJ, time + 1});
          }
        }
      }
    }

    for (int i = 0; i < grid.size(); ++i)
    {
      for (int j = 0; j < grid[0].size(); ++j)
      {
        if (grid[i][j] == 1)
          return -1;
      }
    }
    return ans;
  }
};
