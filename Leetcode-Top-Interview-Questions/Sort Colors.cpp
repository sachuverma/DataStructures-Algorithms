/*
Sort Colors
===========

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Follow up:
Could you solve this problem without using the library's sort function?
Could you come up with a one-pass algorithm using only O(1) constant space?


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

Hint #1  
A rather straight forward solution is a two-pass algorithm using counting sort.

Hint #2  
Iterate the array counting number of 0's, 1's, and 2's.

Hint #3  
Overwrite array with the total number of 0's, then 1's and followed by 2's.
*/

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    vector<int> colorCounts = {0, 0, 0};
    for (auto &i : nums)
      colorCounts[i]++;
    for (int i = 0; i < nums.size(); ++i)
    {
      if (colorCounts[0] > 0)
      {
        nums[i] = 0;
        colorCounts[0]--;
      }
      else if (colorCounts[1] > 0)
      {
        nums[i] = 1;
        colorCounts[1]--;
      }
      else if (colorCounts[2] > 0)
      {
        nums[i] = 2;
        colorCounts[2]--;
      }
    }
  }
};
