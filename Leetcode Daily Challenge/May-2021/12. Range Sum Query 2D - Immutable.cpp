/*
Range Sum Query 2D - Immutable
==============================

Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Example 1:
Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]

Output
[null, 8, 11, 12]

Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
-105 <= matrix[i][j] <= 105
0 <= row1 <= row2 < m
0 <= col1 <= col2 < n
At most 104 calls will be made to sumRegion.
*/

class NumMatrix
{
public:
  vector<vector<int>> prefix;

  NumMatrix(vector<vector<int>> &matrix)
  {
    prefix = matrix;
    for (int i = 0; i < prefix.size(); ++i)
    {
      for (int j = 1; j < prefix[0].size(); ++j)
        prefix[i][j] = prefix[i][j] + prefix[i][j - 1];
    }

    for (int j = 0; j < prefix[0].size(); ++j)
    {
      for (int i = 1; i < prefix.size(); ++i)
        prefix[i][j] = prefix[i][j] + prefix[i - 1][j];
    }
  }

  int sumRegion(int r1, int c1, int r2, int c2)
  {
    int ans = prefix[r2][c2];
    if (r1 > 0 && c1 > 0)
      ans += prefix[r1 - 1][c1 - 1];
    if (r1 > 0)
      ans -= prefix[r1 - 1][c2];
    if (c1 > 0)
      ans -= prefix[r2][c1 - 1];
    return ans;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
