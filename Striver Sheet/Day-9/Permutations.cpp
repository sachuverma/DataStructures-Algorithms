/*
Permutations
============

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

class Solution
{
public:
  void dfs(vector<int> nums, int i, vector<vector<int>> &ans)
  {
    if (i == nums.size() - 1)
    {
      ans.push_back(nums);
      return;
    }

    for (int j = i; j < nums.size(); ++j)
    {
      swap(nums[i], nums[j]);
      dfs(nums, i + 1, ans);
      swap(nums[i], nums[j]);
    }
  }

  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> ans;
    dfs(nums, 0, ans);
    return ans;
  }
};
