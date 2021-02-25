/*
Shortest Unsorted Continuous Subarray
======================================

Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

Example 1:
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Example 2:
Input: nums = [1,2,3,4]
Output: 0

Example 3:
Input: nums = [1]
Output: 0

Constraints:
1 <= nums.length <= 104
-105 <= nums[i] <= 105

Follow up: Can you solve it in O(n) time complexity?
*/

class Solution
{
public:
  int findUnsortedSubarray(vector<int> &nums)
  {
    int ans = 0, n = nums.size();
    if (n <= 1)
      return 0;

    int i = 0, prev = nums[0];
    for (i = 1; i < n; ++i)
    {
      if (prev > nums[i])
        break;
      prev = nums[i];
    }

    if (i == n)
      return 0;

    int j = 0, next = nums[n - 1];
    for (j = n - 1; j >= 0; --j)
    {
      if (next < nums[j])
        break;
      next = nums[j];
    }

    i--;
    j++;

    int mi = INT_MAX, ma = INT_MIN;
    for (int k = i; k <= j; ++k)
    {
      mi = min(mi, nums[k]);
      ma = max(ma, nums[k]);
    }

    for (int k = 0; k < i; ++k)
    {
      if (nums[k] > mi)
      {
        i = k;
        break;
      }
    }

    for (int k = n - 1; k > j; --k)
    {
      if (nums[k] < ma)
      {
        j = k;
        break;
      }
    }

    return j - i + 1;
  }
};
