/*
Find Peak Element
=================

A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

Constraints:
1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.
*/

class Solution
{
public:
  int findPeakElement(vector<int> &A)
  {
    int n = A.size();
    int i = 0, j = n - 1;

    if (n == 1)
      return 0;
    if (A[0] > A[1])
      return 0;
    if (A[n - 1] > A[n - 2])
      return n - 1;

    while (i <= j)
    {
      int m = (i + j) / 2;

      int left = (m - 1 >= 0) ? A[m - 1] : INT_MIN;
      int right = (m + 1 < n) ? A[m + 1] : INT_MIN;

      if (left < A[m] && right < A[m])
        return m;
      else if (left < A[m] && A[m] < right)
        i = m + 1;
      else
        j = m - 1;
    }

    return -1;
  }
};