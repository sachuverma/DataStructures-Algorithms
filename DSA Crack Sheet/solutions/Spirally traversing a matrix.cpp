/*
Spirally traversing a matrix
============================

Given a matrix of size R*C. Traverse the matrix in spiral form.

Example 1:
Input:
R = 4, C = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

Example 2:
Input:
R = 3, C = 4  
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7

Your Task:
You dont need to read input or print anything. Complete the function spirallyTraverse() that takes matrix, R and C as input parameters and returns a list of integers denoting the spiral traversal of matrix. 

Expected Time Complexity: O(R*C)
Expected Auxiliary Space: O(R*C)

Constraints:
1 <= R, C <= 100
0 <= matrixi <= 100
*/

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
  int count = r * c;
  vector<int> ans;
  int tl = 0, tr = c - 1, lt = 0, lb = r - 1;
  while (count > 0)
  {

    for (int i = tl; i <= tr && count > 0; ++i)
    {
      ans.push_back(matrix[lt][i]);
      count--;
    }
    lt++;
    if (count <= 0)
      break;

    for (int i = lt; i <= lb && count > 0; ++i)
    {
      ans.push_back(matrix[i][tr]);
      count--;
    }
    tr--;
    if (count <= 0)
      break;

    for (int i = tr; i >= tl && count > 0; --i)
    {
      ans.push_back(matrix[lb][i]);
      count--;
    }
    lb--;
    if (count <= 0)
      break;

    for (int i = lb; i >= lt && count > 0; --i)
    {
      ans.push_back(matrix[i][tl]);
      count--;
    }
    tl++;
    if (count <= 0)
      break;
  }
  return ans;
}
