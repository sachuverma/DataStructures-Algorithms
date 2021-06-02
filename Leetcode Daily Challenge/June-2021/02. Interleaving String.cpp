/*
Interleaving String
===================

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

Example 3:
Input: s1 = "", s2 = "", s3 = ""
Output: true

Constraints:
0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.

Follow up: Could you solve it using only O(s2.length) additional memory space?
*/

class Solution
{
public:
  bool dfs(string a, string b, string c, int ia, int ib, int ic, vector<vector<int>> &memo)
  {
    if (ic == c.size())
    {
      if (ia == a.size() && ib == b.size())
        return true;
      return false;
    }

    if (memo[ia][ib] != -1)
      return memo[ia][ib];

    if (a[ia] == c[ic] && dfs(a, b, c, ia + 1, ib, ic + 1, memo))
      return memo[ia][ib] = true;
    if (b[ib] == c[ic] && dfs(a, b, c, ia, ib + 1, ic + 1, memo))
      return memo[ia][ib] = true;
    return memo[ia][ib] = false;
  }

  bool isInterleave(string s1, string s2, string s3)
  {
    vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    return dfs(s1, s2, s3, 0, 0, 0, memo);
  }
};
