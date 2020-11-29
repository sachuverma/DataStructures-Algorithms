/*
Number of Longest Increasing Subsequence
========================================

Given an integer array nums, return the number of longest increasing subsequences.


Example 1:
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

Constraints:
0 <= nums.length <= 2000
-106 <= nums[i] <= 106
*/

class Solution
{
public:
  int findNumberOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    if (n < 2)
      return n;

    vector<pair<int, int>> dp(n, {1, 1});
    int maxlen = 1;
    int ans = 1;

    for (int i = 1; i < n; i++)
    {
      for (int j = i - 1; j >= 0; j--)
      {
        if (nums[j] >= nums[i])
          continue;
        if (dp[j].first + 1 > dp[i].first)
        {
          dp[i].first = dp[j].first + 1;
          dp[i].second = dp[j].second;
        }
        else if (dp[j].first + 1 == dp[i].first)
          dp[i].second += dp[j].second;
      }

      if (dp[i].first > maxlen)
      {
        maxlen = dp[i].first;
        ans = dp[i].second;
      }
      else if (dp[i].first == maxlen)
        ans += dp[i].second;
    }
    return ans;
  }
};
