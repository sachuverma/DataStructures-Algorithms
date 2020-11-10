/*
3Sum
====

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

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
    if (nums.size() < 3)
      return {};

    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size() - 2; ++i)
    {
      if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
      {
        int sum = -nums[i];
        int low = i + 1, high = nums.size() - 1;
        while (low < high)
        {
          if (nums[low] + nums[high] == sum)
          {
            ans.push_back({nums[i], nums[low], nums[high]});
            while (low < high && nums[low] == nums[low + 1])
              low++;
            while (low < high && nums[high] == nums[high - 1])
              high--;
            low++;
            high--;
          }
          else if (nums[low] + nums[high] > sum)
            high--;
          else
            low++;
        }
      }
    }

    return ans;
  }
};
