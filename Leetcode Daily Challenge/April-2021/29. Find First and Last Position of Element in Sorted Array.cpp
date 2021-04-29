/*
Find First and Last Position of Element in Sorted Array
========================================================

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
    int ans1 = -1, ans2 = -1;
    int i = 0, j = nums.size() - 1;

    while (i <= j)
    {
      int mid = (i + j) / 2;
      if (nums[mid] == target)
      {
        ans1 = mid;
        j = mid - 1;
      }
      else if (nums[mid] > target)
        j = mid - 1;
      else
        i = mid + 1;
    }

    i = 0, j = nums.size() - 1;

    while (i <= j)
    {
      int mid = (i + j) / 2;
      if (nums[mid] == target)
      {
        ans2 = mid;
        i = mid + 1;
      }
      else if (nums[mid] > target)
        j = mid - 1;
      else
        i = mid + 1;
    }

    return {ans1, ans2};
  }
};
