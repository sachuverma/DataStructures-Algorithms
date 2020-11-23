/*
Pascal's Triangle
=================

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution
{
public:
  vector<vector<int>> generate(int n)
  {
    if (n == 0)
      return {};
    if (n == 1)
      return {{1}};

    vector<vector<int>> ans;
    ans.push_back({1});
    ans.push_back({1, 1});

    for (int i = 3; i <= n; ++i)
    {
      vector<int> subans;
      subans.push_back(1);
      for (int j = 1; j <= i - 2; ++j)
        subans.push_back(ans[i - 2][j - 1] + ans[i - 2][j]);
      subans.push_back(1);
      ans.push_back(subans);
    }

    return ans;
  }
};
