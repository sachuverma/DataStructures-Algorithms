/*
Reverse Pairs
=============

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

Example 1:
Input: nums = [1,3,2,3,1]
Output: 2

Example 2:
Input: nums = [2,4,3,5,1]
Output: 3

Constraints:
1 <= nums.length <= 5 * 104
231 <= nums[i] <= 231 - 1
*/

class Solution
{
public:
  int merge(vector<int> &nums, int low, int mid, int high)
  {
    int count = 0;
    int i = low, j = mid + 1;

    // count pairs
    while (i <= mid)
    {
      while (j <= high && nums[i] > 2LL * nums[j])
        j++;
      count += (j - (mid + 1));
      i++;
    }

    // merge the sorted arrays
    vector<int> temp;
    i = low;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
      if (nums[i] < nums[j])
        temp.push_back(nums[i++]);
      else
        temp.push_back(nums[j++]);
    }

    while (i <= mid)
      temp.push_back(nums[i++]);
    while (j <= high)
      temp.push_back(nums[j++]);

    for (int k = low; k <= high; ++k)
      nums[k] = temp[k - low];

    return count;
  }

  int mergeSort(vector<int> &nums, int low, int high)
  {
    int count = 0;
    if (low < high)
    {
      int mid = (low + high) / 2;
      count += mergeSort(nums, low, mid);
      count += mergeSort(nums, mid + 1, high);
      count += merge(nums, low, mid, high);
    }
    return count;
  }

  int reversePairs(vector<int> &nums)
  {
    return mergeSort(nums, 0, nums.size() - 1);
  }
};
