/*
4Sum
====

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:
1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &A, int tar)
  {
    vector<vector<int>> ans;
    sort(A.begin(), A.end());
    int n = A.size();

    for (int i = 0; i < n - 3; ++i)
    {
      for (int j = i + 1; j < n - 2; ++j)
      {
        int k = j + 1, l = n - 1;
        while (k < l)
        {
          if (A[k] + A[l] == tar - (A[i] + A[j]))
          {
            ans.push_back({A[i], A[j], A[k], A[l]});
            while (k < l && A[k] == A[k + 1])
              k++;
            while (k < l && A[l] == A[l - 1])
              l--;
            k++;
            l--;
          }
          else if (A[k] + A[l] < tar - (A[i] + A[j]))
            k++;
          else
            l--;
        }
        while (j < n - 2 && A[j] == A[j + 1])
          j++;
      }
      while (i < n - 3 && A[i] == A[i + 1])
        i++;
    }

    return ans;
  }
};