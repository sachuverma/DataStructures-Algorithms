/*
Minimum Operations to Reduce X to Zero
=========================================

You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.


Example 1:
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

Example 2:
Input: nums = [5,6,7,8,9], x = 4
Output: -1

Example 3:
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109

Hint #1  
Think in reverse; instead of finding the minimum prefix + suffix, find the maximum subarray.

Hint #2  
Finding the maximum subarray is standard and can be done greedily.
*/

class Solution
{
public:
  int minOperations(vector<int> &nums, int x)
  {
    unordered_map<int, int> left;
    int res = INT_MAX;
    for (auto l = 0, sum = 0; l < nums.size() && sum <= x; ++l)
    {
      left[sum] = l;
      sum += nums[l];
    }
    for (int r = nums.size() - 1, sum = 0; r >= 0 && sum <= x; --r)
    {
      auto it = left.find(x - sum);
      if (it != end(left) && r + 1 >= it->second)
      {
        res = min(res, (int)nums.size() - r - 1 + it->second);
      }
      sum += nums[r];
    }
    return res == INT_MAX ? -1 : res;
  }
};
