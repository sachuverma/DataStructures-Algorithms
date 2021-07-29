/*
01 Matrix
=========

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 
Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
*/

class Solution
{
public:
  int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
  {
    auto ans = mat;
    int n = mat.size(), m = mat[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (mat[i][j] == 0)
        {
          q.push({i, j});
          mat[i][j] = -1;
        }
      }
    }

    int steps = 0;
    while (q.size())
    {
      steps++;

      for (int i = q.size(); i > 0; --i)
      {
        auto curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;

        for (auto &dir : dirs)
        {
          int nx = x + dir[0], ny = y + dir[1];
          if (nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] != -1)
          {
            mat[nx][ny] = -1;
            ans[nx][ny] = steps;
            q.push({nx, ny});
          }
        }
      }
    }

    return ans;
  }
};