/*
Search a 2D Matrix II
=====================

Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Example 1:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Example 2:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false

Constraints:
m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109
*/

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int n = matrix.size(), m = matrix[0].size();
    int i = n - 1, j = 0;

    while (i >= 0 && j < m)
    {
      if (matrix[i][j] == target)
        return true;
      else if (matrix[i][j] < target)
        j++;
      else
        i--;
    }
    return false;
  }
};
