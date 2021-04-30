/*
Palindrome Partitioning
=======================

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]

Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.
*/

class Solution
{
public:
  bool check(string &s, int i, int j)
  {
    while (i < j)
    {
      if (s[i++] != s[j--])
        return false;
    }
    return true;
  }

  void dfs(string &s, int idx, vector<vector<string>> &ans, vector<string> atn)
  {
    if (s.size() == idx)
    {
      ans.push_back(atn);
      return;
    }

    for (int i = idx; i < s.size(); ++i)
    {
      if (check(s, idx, i))
      {
        atn.push_back(s.substr(idx, i - idx + 1));
        dfs(s, i + 1, ans, atn);
        atn.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s)
  {
    vector<vector<string>> ans;
    dfs(s, 0, ans, {});
    return ans;
  }
};
