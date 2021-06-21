/*
Pascal's Triangle
=================

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

Constraints:
1 <= numRows <= 30
*/

class Solution
{
public:
  vector<vector<int>> generate(int n)
  {
    if (n == 1)
      return {{1}};
    if (n == 2)
      return {{1}, {1, 1}};

    vector<vector<int>> ans = {{1}, {1, 1}};

    for (int i = 3; i <= n; ++i)
    {
      vector<int> temp(i, 0);
      temp[0] = 1;
      temp[i - 1] = 1;

      for (int j = 1; j < i - 1; ++j)
        temp[j] = ans[i - 2][j - 1] + ans[i - 2][j];

      ans.push_back(temp);
    }

    return ans;
  }
};
