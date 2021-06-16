/*
Generate Parentheses
====================

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:
1 <= n <= 8
*/

class Solution
{
public:
  void dfs(int n, int o, int c, vector<string> &ans, string stn)
  {
    if (o == n && c == n)
    {
      ans.push_back(stn);
      return;
    }

    if (o < n)
      dfs(n, o + 1, c, ans, stn + "(");
    if (c < o)
      dfs(n, o, c + 1, ans, stn + ")");
  }

  vector<string> generateParenthesis(int n)
  {
    vector<string> ans;
    dfs(n, 0, 0, ans, "");
    return ans;
  }
};
