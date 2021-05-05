/*
Longest Palindromic Substring
=============================

Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Example 3:
Input: s = "a"
Output: "a"

Example 4:
Input: s = "ac"
Output: "a"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/

class Solution
{
public:
  string longestPalindrome(string s)
  {
    int n = s.size(), max_len = 1;
    string ans = s.substr(0, 1);
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;
    for (int i = 0; i + 1 < n; ++i)
    {
      if (s[i] == s[i + 1])
      {
        max_len = 2;
        ans = s.substr(i, 2);
        dp[i][i + 1] = 1;
      }
    }

    for (int gap = 2; gap < n; ++gap)
    {
      for (int i = 0; i + gap < n; ++i)
      {
        int j = i + gap;
        if (s[i] == s[j] && dp[i + 1][j - 1])
        {
          if (max_len < gap + 1)
          {
            max_len = gap + 1;
            ans = s.substr(i, gap + 1);
          }
          dp[i][j] = 1;
        }
      }
    }

    return ans;
  }
};
