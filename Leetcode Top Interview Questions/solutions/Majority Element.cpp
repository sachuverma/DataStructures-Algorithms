/*
Majority Element
================

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2
*/

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    int ans = 0, ma = INT_MIN;
    sort(nums.begin(), nums.end());
    int i = 0;
    while (i < nums.size())
    {
      int up = upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
      int low = lower_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
      if (up - low > ma)
      {
        ans = nums[i];
        ma = up - low;
      }
      i = up;
    }

    return ans;
  }
};
