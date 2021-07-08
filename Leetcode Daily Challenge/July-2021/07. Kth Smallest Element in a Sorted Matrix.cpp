/*
Kth Smallest Element in a Sorted Matrix
========================================

Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example 1:
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Example 2:
Input: matrix = [[-5]], k = 1
Output: -5

Constraints:
n == matrix.length
n == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2
*/

class Solution
{
public:
  int kthSmallest(vector<vector<int>> &A, int k)
  {
    int n = A.size(), m = A[0].size();
    int l = A[0][0], h = A[n - 1][m - 1], ans;

    while (l < h)
    {
      int mid = (l + h) / 2;
      int count = 0, j = m - 1;

      for (int i = 0; i < n; ++i)
      {
        while (j >= 0 && A[i][j] > mid)
          j--;
        count += j + 1;
      }

      if (count < k)
        l = mid + 1;
      else
        h = mid;
    }
    return l;
  }
};