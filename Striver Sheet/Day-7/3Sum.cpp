/*
3Sum
====

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums = []
Output: []

Example 3:
Input: nums = [0]
Output: []

Constraints:
0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    int i = 0;

    while (i < n - 2)
    {
      int j = i + 1;
      int k = n - 1;

      while (j < k)
      {
        if (nums[j] + nums[k] == -nums[i])
        {
          ans.push_back({nums[i], nums[j], nums[k]});
          while (j < k && nums[j] == nums[j + 1])
            j++;
          while (j < k && nums[k] == nums[k - 1])
            k--;
          j++;
          k--;
        }
        else if (nums[j] + nums[k] < -nums[i])
        {
          while (j < k && nums[j] == nums[j + 1])
            j++;
          j++;
        }
        else
        {
          while (j < k && nums[k] == nums[k - 1])
            k--;
          k--;
        }
      }

      while (i < n - 1 && nums[i] == nums[i + 1])
        i++;
      i++;
    }

    return ans;
  }
};
