/*
Kth Largest Element in an Array
===============================

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

Constraints:
1 <= k <= nums.length <= 104
-104 <= nums[i] <= 104
*/

class Solution
{
public:
  int quickSelect(vector<int> &nums, int k, int low, int high)
  {
    while (low <= high)
    {
      int pos = partition(nums, low, high);
      if (pos == k)
        return nums[pos];
      else if (pos > k)
        high = pos - 1;
      else
        low = pos + 1;
    }
    return INT_MIN;
  }

  int partition(vector<int> &nums, int left, int right)
  {
    int pivot = nums[left], l = left + 1, r = right;
    while (l <= r)
    {
      if (nums[l] < pivot && nums[r] > pivot)
        swap(nums[l++], nums[r--]);
      if (nums[l] >= pivot)
        l++;
      if (nums[r] <= pivot)
        r--;
    }
    swap(nums[left], nums[r]);
    return r;
  }

  int findKthLargest(vector<int> &nums, int k)
  {
    return quickSelect(nums, k - 1, 0, nums.size() - 1);
  }
};