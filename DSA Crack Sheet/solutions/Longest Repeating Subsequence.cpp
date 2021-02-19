/*
Longest Repeating Subsequence
=============================

Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

Exampel 1:
Input: str = "axxxy"
Output: 2
Explanation: The longest repeating subsequenece
is "xx".

Example 2:
Input: str = "aab"
output: 1
Explanation: The longest reapting subsequenece
is "a".

Your Task:
You don't need to read or print anything. Your task is to complete the function LongestRepeatingSubsequence() which takes str as input parameter and returns the length of the longest repeating subsequnece.

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)

Constraints:
1 <= |str| <= 500
*/

int lcs(int x, int y, string s1, string s2)
{
  int dp[x + 1][y + 1];
  for (int i = 0; i <= x; ++i)
  {
    for (int j = 0; j <= y; ++j)
    {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else
      {
        if (i != j && s1[i - 1] == s2[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[x][y];
}

int LongestRepeatingSubsequence(string str)
{
  int n = str.size();
  return lcs(n, n, str, str);
}
