/*
Subsets II
==========

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

class Solution
{
public:
  void dfs(vector<int> &nums, int i, vector<int> atn, vector<vector<int>> &ans)
  {
    ans.push_back(atn);
    for (int j = i; j < nums.size(); ++j)
    {
      if (j != i && nums[j] == nums[j - 1])
        continue;
      atn.push_back(nums[j]);
      dfs(nums, j + 1, atn, ans);
      atn.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    dfs(nums, 0, {}, ans);
    return ans;
  }
};
