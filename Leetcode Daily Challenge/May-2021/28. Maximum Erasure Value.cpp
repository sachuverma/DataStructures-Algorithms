/*
Maximum Erasure Value
=====================

You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

Example 1:
Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Example 2:
Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 104

Hint #1  
The main point here is for the subarray to contain unique elements for each index. Only the first subarrays starting from that index have unique elements.

Hint #2  
This can be solved using the two pointers technique
*/

class Solution
{
public:
  int maximumUniqueSubarray(vector<int> &nums)
  {
    int ans = 0;
    int i = 0, j = 0, n = nums.size(), curr = 0;
    unordered_set<int> vis;

    while (j < n)
    {
      while (i < j && vis.find(nums[j]) != vis.end())
      {
        curr -= nums[i];
        vis.erase(nums[i]);
        i++;
      }

      vis.insert(nums[j]);
      curr += nums[j];
      j++;

      ans = max(ans, curr);
    }

    return ans;
  }
};
