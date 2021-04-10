/*
Longest Increasing Path in a Matrix
===================================

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Example 1:
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Example 3:
Input: matrix = [[1]]
Output: 1

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
*/

class Solution
{
public:
  int dirs[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  int dfs(vector<vector<int>> &mat, int r, int c, vector<vector<int>> &memo)
  {
    if (memo[r][c] != -1)
      return memo[r][c];

    int n = mat.size(), m = mat[0].size();
    int ans = 0;
    for (auto &dir : dirs)
    {
      int nextR = r + dir[0], nextC = c + dir[1];
      if (nextR < 0 || nextC < 0 || nextR >= n || nextC >= m || mat[r][c] >= mat[nextR][nextC])
        continue;
      ans = max(ans, dfs(mat, nextR, nextC, memo));
    }

    memo[r][c] = ans + 1;
    return memo[r][c];
  }

  int longestIncreasingPath(vector<vector<int>> &matrix)
  {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        int curr_ans = dfs(matrix, i, j, memo);
        ans = max(ans, curr_ans);
      }
    }
    return ans;
  }
};
