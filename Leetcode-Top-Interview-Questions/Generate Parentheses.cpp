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
  void backtrack(vector<string> &ans, int n, int open, int close, string out = "")
  {
    if (out.length() == n * 2)
    {
      ans.push_back(out);
      return;
    }

    if (open < n)
      backtrack(ans, n, open + 1, close, out + "(");
    if (close < open)
      backtrack(ans, n, open, close + 1, out + ")");
  }

public:
  vector<string> generateParenthesis(int n)
  {
    vector<string> ans;
    backtrack(ans, n, 0, 0);
    return ans;
  }
};