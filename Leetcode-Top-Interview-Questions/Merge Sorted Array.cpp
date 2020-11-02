/*
Merge Sorted Array
==================

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
Output: [1,2,2,3,5,6]


Constraints:
-10^9 <= nums1[i], nums2[i] <= 10^9
nums1.length == m + n
nums2.length == n

Hint #1  
You can easily solve this problem if you simply think about two elements at a time rather than two arrays. We know that each of the individual arrays is sorted. What we don't know is how they will intertwine. Can we take a local decision and arrive at an optimal solution?

Hint #2  
If you simply consider one element each at a time from the two arrays and make a decision and proceed accordingly, you will arrive at the optimal solution.
*/

class Solution
{
public:
  void merge(vector<int> &A, int m, vector<int> &B, int n)
  {
    int a = m - 1;
    int b = n - 1;
    int i = m + n - 1;

    while (a >= 0 && b >= 0)
    {
      if (A[a] > B[b])
        A[i--] = A[a--];
      else
        A[i--] = B[b--];
    }

    while (b >= 0)
      A[i--] = B[b--];
  }
};
