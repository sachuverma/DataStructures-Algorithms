/*
Longest Harmonious Subsequence
==============================

We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

Example 2:
Input: nums = [1,2,3,4]
Output: 2

Example 3:
Input: nums = [1,1,1,1]
Output: 0

Constraints:
1 <= nums.length <= 2 * 104
-109 <= nums[i] <= 109
*/

class Solution
{
public:
  int findLHS(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int ans = 0;
    int i = 0, j = 0;
    while (i < nums.size() && j < nums.size())
    {
      while (j < nums.size() && (nums[j] == nums[i] || nums[j] == nums[i] + 1))
        j++;
      if (i != j && nums[i] == nums[j - 1])
        i++;
      else
      {
        ans = max(ans, j - i);
        i++;
      }
      j = i;
    }
    return ans == 1 ? 0 : ans;
  }
};
