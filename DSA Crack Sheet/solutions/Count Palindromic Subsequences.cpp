/*
Count Palindromic Subsequences
==============================

Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) which could be formed from the string str.

Example 1:
Input: 
Str = "abcd"
Output: 
4
Explanation:
palindromic subsequence are : "a" ,"b", "c" ,"d"

Example 2:
Input: 
Str = "aab"
Output: 
4
Explanation:
palindromic subsequence are :"a", "a", "b", "aa"

Your Task:
You don't need to read input or print anything. Your task is to complete the function countPs() which takes a string str as input parameter and returns the number of palindromic subsequence.

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N*N)

Constraints:
1<=length of string str <=30
*/

int countPS(string str, int i, int j, vector<vector<int>> &dp)
{
  if (i > j)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  if (i == j)
    return dp[i][j] = 1;

  else if (str[i] == str[j])
    return dp[i][j] = countPS(str, i + 1, j, dp) + countPS(str, i, j - 1, dp) + 1;

  else
    return dp[i][j] = countPS(str, i + 1, j, dp) + countPS(str, i, j - 1, dp) - countPS(str, i + 1, j - 1, dp);
}

int countPS(string str)
{
  int n = str.size();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  return countPS(str, 0, n - 1, dp);
}
