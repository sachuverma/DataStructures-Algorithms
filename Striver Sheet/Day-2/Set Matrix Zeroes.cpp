/*
Set Matrix Zeroes
=================

Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
*/

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int n = matrix.size(), m = matrix[0].size();
    bool col = true;

    for (int i = 0; i < n; ++i)
    {
      if (matrix[i][0] == 0)
        col = false;
      for (int j = 1; j < m; ++j)
      {
        if (matrix[i][j] == 0)
        {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    for (int i = 1; i < n; ++i)
    {
      if (matrix[i][0] == 0)
      {
        for (int j = 1; j < m; ++j)
          matrix[i][j] = 0;
      }
    }

    for (int j = 1; j < m; ++j)
    {
      if (matrix[0][j] == 0)
      {
        for (int i = 1; i < n; ++i)
          matrix[i][j] = 0;
      }
    }

    if (matrix[0][0] == 0)
    {
      for (int i = 0; i < m; ++i)
        matrix[0][i] = 0;
    }

    if (!col)
    {
      for (int i = 0; i < n; ++i)
        matrix[i][0] = 0;
    }
  }
};
