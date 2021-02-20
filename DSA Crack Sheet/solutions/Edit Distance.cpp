/*
Edit Distance
=============

Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:

Insert
Remove
Replace


Example 1:
Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.

Example 2:
Input : 
s = "gfg", t = "gfg"
Output: 
0
Explanation: Both strings are same.

Your Task:
You don't need to read or print anything. Your task is to complete the function editDistance() which takes strings s and t as input parameters and returns the minimum number of operation required to make both strings equal. 

Expected Time Complexity: O(|s|*|t|)
Expected Space Complexity: O(|s|*|t|)

Constraints:
1 <= Length of both strings <= 100
Both the strings are in lowercase.
*/

int Min(int x, int y, int z) { return min(min(x, y), z); }

int editDist(string str1, string str2, int m, int n, vector<vector<int>> &dp)
{
  if (dp[m][n] != -1)
    return dp[m][n];

  if (m == 0)
  {
    dp[m][n] = n;
    return n;
  }

  if (n == 0)
  {
    dp[m][n] = m;
    return m;
  }

  if (str1[m - 1] == str2[n - 1])
  {
    int ans = editDist(str1, str2, m - 1, n - 1, dp);
    dp[m][n] = ans;
    return ans;
  }

  int ans = 1 + Min(editDist(str1, str2, m, n - 1, dp), editDist(str1, str2, m - 1, n, dp), editDist(str1, str2, m - 1, n - 1, dp));
  dp[m][n] = ans;
  return ans;
}

int editDistance(string s, string t)
{
  int m = s.size(), n = t.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
  editDist(s, t, m, n, dp);
  return dp[m][n];
  ;
}
