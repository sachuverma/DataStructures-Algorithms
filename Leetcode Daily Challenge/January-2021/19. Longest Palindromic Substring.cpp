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

Hint #1  
How can we reuse a previously computed palindrome to compute a larger palindrome?

Hint #2  
If “aba” is a palindrome, is “xabax” and palindrome? Similarly is “xabay” a palindrome?

Hint #3  
Complexity based hint:
If we use brute-force and check whether for every start and end position a substring is a palindrome we have O(n^2) start - end pairs and O(n) palindromic checks. Can we reduce the time for palindromic checks to O(1) by reusing some previous computation.
*/

class Solution
{
public:
  string longestPalindrome(string s)
  {
    if (!s.size())
      return "";

    int index = 0, length = 1;
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

    for (int i = 0; i < s.size(); ++i)
      dp[i][i] = 1;

    for (int i = 0; i < s.size() - 1; ++i)
    {
      if (s[i] == s[i + 1])
      {
        dp[i][i + 1] = 1;
        length = 2;
        index = i;
      }
    }

    for (int gap = 2; gap < s.size(); ++gap)
    {
      for (int i = 0; i + gap < s.size(); ++i)
      {
        if (s[i] == s[i + gap] && dp[i + 1][i + gap - 1] == 1)
        {
          dp[i][i + gap] = 1;
          if (gap + 1 > length)
          {
            length = gap + 1;
            index = i;
          }
        }
      }
    }

    return s.substr(index, length);
  }
};
