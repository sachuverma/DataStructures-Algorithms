/*
Sort the Matrix Diagonally
==========================

A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.

Example 1:
Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100

Hint #1  
Use a data structure to store all values of each diagonal.

Hint #2  
How to index the data structure with the id of the diagonal?

Hint #3  
All cells in the same diagonal (i,j) have the same difference so we can get the diagonal of a cell using the difference i-j.
*/

class Solution
{
public:
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
  {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<vector<int>> pending;
    pending.push({mat[0][m - 1], 0, m - 1});
    visited[0][m - 1] = 1;

    while (pending.size())
    {
      int size = pending.size();

      vector<int> val;
      vector<vector<int>> pos;

      for (int i = 0; i < size; ++i)
      {
        auto e = pending.front();
        pending.pop();
        int v = e[0], x = e[1], y = e[2];

        val.push_back(v);
        pos.push_back({x, y});

        if (y - 1 >= 0 && !visited[x][y - 1])
        {
          pending.push({mat[x][y - 1], x, y - 1});
          visited[x][y - 1] = 1;
        }

        if (x + 1 < n && !visited[x + 1][y])
        {
          pending.push({mat[x + 1][y], x + 1, y});
          visited[x + 1][y] = 1;
        }
      }

      sort(val.begin(), val.end());
      for (int i = 0; i < size; ++i)
      {
        mat[pos[i][0]][pos[i][1]] = val[i];
      }
    }

    return mat;
  }
};
