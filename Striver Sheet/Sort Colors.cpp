/*
Sort Colors
===========

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

Example 3:
Input: nums = [0]
Output: [0]

Example 4:
Input: nums = [1]
Output: [1]

Constraints:
n == nums.length
1 <= n <= 300
nums[i] is 0, 1, or 2.

Follow up:
Could you solve this problem without using the library's sort function?
Could you come up with a one-pass algorithm using only O(1) constant space?
*/

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int c0 = 0, c1 = 0, c2 = 0;
    for (auto &i : nums)
    {
      if (i == 0)
        c0++;
      else if (i == 1)
        c1++;
      else
        c2++;
    }
    int i = 0;
    while (c0 > 0 || c1 > 0 || i < nums.size())
    {
      if (c0-- > 0)
        nums[i++] = 0;
      else if (c1-- > 0)
        nums[i++] = 1;
      else
        nums[i++] = 2;
    }
  }
};
