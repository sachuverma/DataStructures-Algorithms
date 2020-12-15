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
  bool palendrome(string s)
  {
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }

  void solution(string s, vector<string> asf, vector<vector<string>> &ans)
  {
    if (s.size() == 0)
    {
      ans.push_back(asf);
      return;
    }

    for (int i = 0; i < s.size(); ++i)
    {
      auto prefix = s.substr(0, i + 1);
      auto rest = s.substr(i + 1);

      if (palendrome(prefix))
      {
        asf.push_back(prefix);
        solution(rest, asf, ans);
        asf.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s)
  {
    vector<vector<string>> ans;
    solution(s, {}, ans);
    return ans;
  }
};
