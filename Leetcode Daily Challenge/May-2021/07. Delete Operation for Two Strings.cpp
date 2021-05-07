/*
Delete Operation for Two Strings
================================

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

Example 1:
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:
Input: word1 = "leetcode", word2 = "etco"
Output: 4

Constraints:
1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
*/

class Solution
{
public:
  int minDistance(string A, string B)
  {
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
    for (int i = 1; i <= A.size(); ++i)
    {
      for (int j = 1; j <= B.size(); ++j)
      {
        if (A[i - 1] == B[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }

    return A.size() + B.size() - 2 * dp[A.size()][B.size()];
  }
};
