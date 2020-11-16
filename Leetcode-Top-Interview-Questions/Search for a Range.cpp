/*
Search for a Range
==================

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].
Follow up: Could you write an algorithm with O(log n) runtime complexity?


Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    int n = nums.size();
    int start = -1, end = n - 1;

    int l = 0, r = n - 1;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (nums[mid] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    if (l < n && l >= 0 && nums[l] == target)
      start = l;
    else
      start = -1;

    l = 0, r = n - 1;
    while (l <= r)
    {
      int mid = (l + r) / 2;
      if (nums[mid] > target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    if (r < n && r >= 0 && nums[r] == target)
      end = r;
    else
      end = -1;
    return {start, end};
  }
};
