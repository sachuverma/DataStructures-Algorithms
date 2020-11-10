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

Hint #1  
If any cell of the matrix has a zero we can record its row and column number using additional memory. But if you don't want to use extra memory then you can manipulate the array instead. i.e. simulating exactly what the question says.

Hint #2  
Setting cell values to zero on the fly while iterating might lead to discrepancies. What if you use some other integer value as your marker? There is still a better approach for this problem with 0(1) space.

Hint #3  
We could have used 2 sets to keep a record of rows/columns which need to be set to zero. But for an O(1) space solution, you can use one of the rows and and one of the columns to keep track of this information.

Hint #4  
We can use the first cell of every row and column as a flag. This flag would determine whether a row or column has been set to zero.
*/

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    set<int> rows, cols;
    for (int i = 0; i < matrix.size(); ++i)
      for (int j = 0; j < matrix[0].size(); ++j)
        if (matrix[i][j] == 0)
        {
          rows.insert(i);
          cols.insert(j);
        }

    for (auto r : rows)
      for (int i = 0; i < matrix[0].size(); ++i)
        matrix[r][i] = 0;

    for (auto c : cols)
      for (int i = 0; i < matrix.size(); ++i)
        matrix[i][c] = 0;
  }
};
