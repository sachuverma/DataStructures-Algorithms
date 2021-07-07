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

vector<vector<string>> ans;
bool palendrome(string &s, int st, int en)
{
  while (st < en)
  {
    if (s[st++] != s[en--])
      return false;
  }
  return true;
}

void dfs(string s, int st, vector<string> &stn)
{
  if (st == s.size())
  {
    ans.push_back(stn);
    return;
  }

  for (int i = st; i < s.size(); ++i)
  {
    if (palendrome(s, st, i))
    {
      stn.push_back(s.substr(st, i - st + 1));
      dfs(s, i + 1, stn);
      stn.pop_back();
    }
  }
}

vector<vector<string>> partition(string s)
{
  ans.clear();
  vector<string> stn;

  dfs(s, 0, stn);

  return ans;
}