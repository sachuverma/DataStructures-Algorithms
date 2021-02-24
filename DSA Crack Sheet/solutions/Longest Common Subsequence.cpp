/*
Longest Common Subsequence
==========================

Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Example 1:
Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.

Example 2:
Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is
"AC" of length 2.
Your Task:
Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=size(str1),size(str2)<=100
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
        if (s1[i - 1] == s2[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
        {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
  }

  return dp[x][y];
}
