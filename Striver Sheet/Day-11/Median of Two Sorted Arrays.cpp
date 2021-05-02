/*
Median of Two Sorted Arrays
===========================

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Example 3:
Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000

Example 4:
Input: nums1 = [], nums2 = [1]
Output: 1.00000

Example 5:
Input: nums1 = [2], nums2 = []
Output: 2.00000

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

Follow up: The overall run time complexity should be O(log (m+n)).
*/

class Solution
{
public:
  double findMedianSortedArrays(vector<int> &input1, vector<int> &input2)
  {
    if (input1.size() > input2.size())
      return findMedianSortedArrays(input2, input1);

    int x = input1.size();
    int y = input2.size();

    int low = 0;
    int high = x;

    while (low <= high)
    {
      int partitionX = (low + high) / 2;
      int partitionY = (x + y + 1) / 2 - partitionX;

      int maxLeftX =
          (partitionX == 0) ? INT_MIN : input1[partitionX - 1];
      int minRightX =
          (partitionX == x) ? INT_MAX : input1[partitionX];

      int maxLeftY =
          (partitionY == 0) ? INT_MIN : input2[partitionY - 1];
      int minRightY =
          (partitionY == y) ? INT_MAX : input2[partitionY];

      if (maxLeftX <= minRightY && maxLeftY <= minRightX)
      {
        if ((x + y) % 2 == 0)
          return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
        else
          return (double)max(maxLeftX, maxLeftY);
      }
      else if (maxLeftX > minRightY)
        high = partitionX - 1;
      else
        low = partitionX + 1;
    }

    return -1;
  }
};
