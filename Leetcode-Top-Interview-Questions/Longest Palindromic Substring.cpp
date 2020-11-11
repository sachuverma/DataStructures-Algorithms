/*
Longest Palindromic Substring
============================

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
    if (s.size() <= 1)
      return s;

    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;
    int Max = 1;
    int start = 0;

    for (int i = 0; i + 1 < n; ++i)
      if (s[i] == s[i + 1])
      {
        dp[i][i + 1] = 1;
        Max = 2;
        start = i;
      }

    for (int gap = 2; gap < n; ++gap)
    {
      for (int i = 0; i + gap < n; ++i)
      {
        int len = gap + 1;
        if (s[i] == s[i + gap] && dp[i + 1][i + gap - 1] == 1)
        {
          dp[i][i + gap] = 1;
          if (Max < len)
          {
            Max = len;
            start = i;
          }
        }
      }
    }

    return s.substr(start, Max);
  }
};
