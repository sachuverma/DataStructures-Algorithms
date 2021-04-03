/*
Ones and Zeroes
==============

You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.

Example 1:
Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

Example 2:
Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.

Constraints:
1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100
*/

class Solution
{
public:
  int knapsack(vector<string> &strs, int m, int n, int i, vector<vector<vector<int>>> &memo)
  {
    if (i == strs.size() || (m == 0 && n == 0))
      return 0;

    if (memo[m][n][i] != -1)
      return memo[m][n][i];

    auto curr = calc(strs[i]);
    if (curr[0] > m || curr[1] > n)
    {
      memo[m][n][i] = knapsack(strs, m, n, i + 1, memo);
      return memo[m][n][i];
    }
    else
    {
      int ans1 = 1 + knapsack(strs, m - curr[0], n - curr[1], i + 1, memo);
      int ans2 = knapsack(strs, m, n, i + 1, memo);
      memo[m][n][i] = max(ans1, ans2);
      return memo[m][n][i];
    }
  }

  vector<int> calc(string s)
  {
    int count0 = 0, count1 = 0;
    for (auto &i : s)
      if (i == '1')
        count1++;
      else
        count0++;
    return {count0, count1};
  }

  int findMaxForm(vector<string> &strs, int m, int n)
  {
    vector<vector<vector<int>>> memo(m + 1, vector<vector<int>>(n + 1, vector<int>(strs.size() + 1, -1)));
    sort(strs.begin(), strs.end());
    return knapsack(strs, m, n, 0, memo);
  }
};
