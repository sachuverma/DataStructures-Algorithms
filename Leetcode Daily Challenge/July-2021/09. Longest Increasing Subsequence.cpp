/*
Longest Increasing Subsequence
==============================

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

Constraints:
1 <= nums.length <= 2500
-104 <= nums[i] <= 104

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

class Solution
{
public:
  int memo[2502][2502];

  int lis(vector<int> &A, int ci, int pi)
  {
    if (ci == A.size())
      return 0;
    int ans = 0;
    if (memo[pi + 1][ci + 1] != -1)
      return memo[pi + 1][ci + 1];
    if (pi == -1 || A[pi] < A[ci])
    {
      ans = max(ans, 1 + lis(A, ci + 1, ci));
    }
    ans = max(ans, lis(A, ci + 1, pi));
    return memo[pi + 1][ci + 1] = ans;
  }

  int lengthOfLIS(vector<int> &A)
  {
    memset(memo, -1, sizeof memo);
    return lis(A, 0, -1);
  }
};