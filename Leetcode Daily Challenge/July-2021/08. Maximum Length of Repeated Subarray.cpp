/*
Maximum Length of Repeated Subarray
===================================

Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

Example 1:
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].

Example 2:
Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100

Hint #1  
Use dynamic programming. dp[i][j] will be the answer for inputs A[i:], B[j:].
*/

class Solution
{
public:
  int findLength(vector<int> &A, vector<int> &B)
  {
    int ans = 0;
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; ++i)
    {
      for (int j = 0; j <= m; ++j)
      {
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        else
        {
          if (A[i - 1] == B[j - 1])
          {
            dp[i][j] = 1 + dp[i - 1][j - 1];
            ans = max(ans, dp[i][j]);
          }
          else
            dp[i][j] = 0;
        }
      }
    }

    return ans;
  }
};
