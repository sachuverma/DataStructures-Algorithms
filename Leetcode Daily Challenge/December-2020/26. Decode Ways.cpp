/*
Decode Ways
===========

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

Example 1:
Input: s = "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: s = "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Example 3:
Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with '0'. We cannot ignore a zero when we face it while decoding. So, each '0' should be part of "10" --> 'J' or "20" --> 'T'.

Example 4:
Input: s = "1"
Output: 1

Constraints:
1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
*/

class Solution
{
  int ways(int i, string s, vector<int> &memo)
  {
    if (memo[i] > -1)
      return memo[i];
    int n = s.size();
    if (i == n)
      return memo[i] = 1;
    if (s[i] == '0')
      return memo[i] = 0;
    int ans = ways(i + 1, s, memo);
    if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
      ans += ways(i + 2, s, memo);
    return memo[i] = ans;
  }

public:
  int numDecodings(string s)
  {
    if (s[0] == '0')
      return 0;
    if (s.size() <= 1)
      return s.size();
    int n = s.size();
    vector<int> dp(n + 1, -1);
    dp[n] = 1;

    // return ways(0, s, dp);

    for (int i = n - 1; i >= 0; i--)
    {
      if (s[i] == '0')
        dp[i] = 0;
      else
      {
        dp[i] = dp[i + 1];
        if (i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7'))
          dp[i] += dp[i + 2];
      }
    }

    return dp[0];
  }
};
