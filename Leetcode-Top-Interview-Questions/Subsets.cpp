/*
Subsets
=======

Given an integer array nums, return all possible subsets (the power set).
The solution set must not contain duplicate subsets.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]


Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

class Solution
{
  void subsets(vector<vector<int>> &ans, vector<int> nums, vector<int> out = {}, int i = 0)
  {
    if (i >= nums.size())
    {
      ans.push_back(out);
      return;
    }

    subsets(ans, nums, out, i + 1);
    out.push_back(nums[i]);
    subsets(ans, nums, out, i + 1);
    out.pop_back();
  }

public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<vector<int>> ans;
    subsets(ans, nums);
    return ans;
  }
};
