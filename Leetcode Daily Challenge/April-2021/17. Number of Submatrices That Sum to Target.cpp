/*
Number of Submatrices That Sum to Target
========================================

Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

Example 1:
Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.

Example 2:
Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

Example 3:
Input: matrix = [[904]], target = 0
Output: 0


Constraints:
1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8

Hint #1  
Using a 2D prefix sum, we can query the sum of any submatrix in O(1) time. Now for each (r1, r2), we can find the largest sum of a submatrix that uses every row in [r1, r2] in linear time using a sliding window.
*/

class Solution
{
public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
  {
    int ans = 0;
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> prefix = matrix;

    for (int i = 1; i < n; ++i)
      for (int j = 0; j < m; ++j)
        prefix[i][j] += prefix[i - 1][j];

    for (int j = 1; j < m; ++j)
      for (int i = 0; i < n; ++i)
        prefix[i][j] += prefix[i][j - 1];

    for (int si = 0; si < n; ++si)
    {
      for (int sj = 0; sj < m; ++sj)
      {
        for (int ei = si; ei < n; ++ei)
        {
          for (int ej = sj; ej < m; ++ej)
          {
            int sum = prefix[ei][ej];
            if (si > 0 && sj > 0)
              sum += prefix[si - 1][sj - 1];
            if (si > 0)
              sum -= prefix[si - 1][ej];
            if (sj > 0)
              sum -= prefix[ei][sj - 1];
            if (sum == target)
              ans++;
          }
        }
      }
    }
    return ans;
  }
};
