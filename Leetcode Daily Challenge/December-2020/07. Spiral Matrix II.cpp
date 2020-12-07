/*
Spiral Matrix II
================

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]

Constraints:
1 <= n <= 20
*/

class Solution
{
public:
  vector<vector<int>> generateMatrix(int n)
  {
    if (!n)
      return {};
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int cnt = 1, tne = n * n, minr = 0, minc = 0, maxr = n - 1, maxc = n - 1;

    while (cnt <= tne)
    {
      for (int j = minc; j <= maxc && cnt <= tne; j++)
      {
        matrix[minr][j] = cnt;
        cout << cnt << " ";
        cnt++;
      }
      minr++;

      for (int i = minr; i <= maxr && cnt <= tne; i++)
      {
        matrix[i][maxc] = cnt;
        cout << cnt << " ";
        cnt++;
      }
      maxc--;

      for (int j = maxc; j >= minc && cnt <= tne; j--)
      {
        matrix[maxr][j] = cnt;
        cout << cnt << " ";
        cnt++;
      }
      maxr--;

      for (int i = maxr; i >= minr && cnt <= tne; i--)
      {
        matrix[i][minc] = cnt;
        cout << cnt << " ";
        cnt++;
      }
      minc++;
    }

    return matrix;
  }
};
