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
  void sortColors(vector<int> &arr)
  {
    int i = 0, j = 0, k = arr.size() - 1;
    int n = arr.size();
    while (i < k && j <= k)
    {
      if (i < n && arr[i] == 0)
        i++;
      j = i;
      if (j > k)
        break;
      while (j < n && arr[j] == 1)
        j++;
      if (j > k)
        break;
      if (j < n && arr[j] == 0)
        swap(arr[i++], arr[j]);
      else if (j < n && arr[j] == 2)
        swap(arr[j], arr[k--]);
    }
  }
};
