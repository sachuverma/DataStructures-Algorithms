/*
Distance of nearest cell having 1
=================================

Given a binary grid. Find the distance of nearest 1 in the grid for each cell.
The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.

Example 1:
Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.

Example 2:
Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a 
distance of 1, 1, 1 and 2 from 1's at (0,0),
(0,2), (2,0) and (1,1) respectively.

Yout Task:
You don't need to read or print anything, Your task is to complete the function nearest() which takes grid as input parameter and returns a matrix of same dimensions where the value at index (i, j) in the resultant matrix signifies the minimum distance of 1 in the matrix from grid[i][j].

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n, m ≤ 500
*/

int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> nearest(vector<vector<int>> grid)
{
  int n = grid.size(), m = grid[0].size();

  queue<vector<int>> q;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if (grid[i][j] == 1)
      {
        q.push({i, j});
        grid[i][j] = -1;
      }
    }
  }

  int dist = 0;

  while (q.size())
  {
    dist++;
    for (int i = q.size(); i > 0; --i)
    {
      auto curr = q.front();
      q.pop();
      int x = curr[0], y = curr[1];

      for (auto &dir : dirs)
      {
        int nx = x + dir[0], ny = y + dir[1];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0)
        {
          q.push({nx, ny});
          grid[nx][ny] = dist;
        }
      }
    }
  }

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if (grid[i][j] == -1)
        grid[i][j] = 0;
    }
  }
  return grid;
}
