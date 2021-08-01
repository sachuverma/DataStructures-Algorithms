/*
Making A Large Island
=====================

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

Example 1:
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Example 2:
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 
Constraints:
n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.
*/

class Solution
{
public:
  int dirs[4][2] = {
      {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  int bfs(vector<vector<int>> &grid, vector<vector<pair<int, int>>> &vis, int r, int c, int id)
  {
    int n = grid.size(), m = grid[0].size();
    int ans = 0;

    queue<pair<int, int>> q;

    q.push({r, c});
    vis[r][c].first = -1;

    while (q.size())
    {
      auto curr = q.front();
      q.pop();
      int x = curr.first, y = curr.second;
      ans++;

      for (auto dir : dirs)
      {
        int nx = x + dir[0], ny = y + dir[1];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1 && vis[nx][ny].first == 0)
        {
          vis[nx][ny].first = -1;
          q.push({nx, ny});
        }
      }
    }

    q.push({r, c});
    vis[r][c].first = ans;
    vis[r][c].second = id;

    while (q.size())
    {
      auto curr = q.front();
      q.pop();
      int x = curr.first, y = curr.second;

      for (auto dir : dirs)
      {
        int nx = x + dir[0], ny = y + dir[1];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1 && vis[nx][ny].first == -1)
        {
          vis[nx][ny].first = ans;
          vis[nx][ny].second = id;
          q.push({nx, ny});
        }
      }
    }

    return ans;
  }

  int largestIsland(vector<vector<int>> &grid)
  {
    int n = grid.size(), m = grid[0].size();
    int ans = 0;

    // { island_size, id }
    vector<vector<pair<int, int>>> vis(n, vector<pair<int, int>>(m, {0, 0}));
    int index_counter = 0;

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (grid[i][j] == 1 && vis[i][j].second == 0)
        {
          index_counter++;
          ans = max(ans, bfs(grid, vis, i, j, index_counter));
        }
      }
    }

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (grid[i][j] == 0)
        {

          int curr = 1;
          unordered_set<int> taken_id;

          if (i - 1 >= 0 && !taken_id.count(vis[i - 1][j].second))
          {
            taken_id.insert(vis[i - 1][j].second);
            curr += vis[i - 1][j].first;
          }

          if (i + 1 < n && !taken_id.count(vis[i + 1][j].second))
          {
            taken_id.insert(vis[i + 1][j].second);
            curr += vis[i + 1][j].first;
          }

          if (j - 1 >= 0 && !taken_id.count(vis[i][j - 1].second))
          {
            taken_id.insert(vis[i][j - 1].second);
            curr += vis[i][j - 1].first;
          }

          if (j + 1 < m && !taken_id.count(vis[i][j + 1].second))
          {
            taken_id.insert(vis[i][j + 1].second);
            curr += vis[i][j + 1].first;
          }

          ans = max(ans, curr);
        }
      }
    }

    return ans;
  }
};