/*
Valid Triangle Number
=====================

Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Example 2:
Input: nums = [4,2,3,4]
Output: 4

Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 1000
*/

class Solution
{
public:
  int triangleNumber(vector<int> &A)
  {
    sort(A.begin(), A.end());
    int ans = 0;

    for (int i = 0; i < A.size(); ++i)
    {
      for (int j = i + 1; j < A.size(); ++j)
      {
        int sum = A[i] + A[j];
        auto it = lower_bound(A.begin() + j + 1, A.end(), sum) - A.begin();
        it--;
        ans += (it - j);
      }
    }

    return ans;
  }
};