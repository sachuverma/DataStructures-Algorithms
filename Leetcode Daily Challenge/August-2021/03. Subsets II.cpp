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
  void dfs(vector<int> &nums, int i, vector<int> atn, set<vector<int>> &ans)
  {
    if (i == nums.size())
    {
      sort(atn.begin(), atn.end());
      ans.insert(atn);
      return;
    }

    dfs(nums, i + 1, atn, ans);
    atn.push_back(nums[i]);
    dfs(nums, i + 1, atn, ans);
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    set<vector<int>> sans;
    dfs(nums, 0, {}, sans);
    vector<vector<int>> ans;
    for (auto &i : sans)
      ans.push_back(i);
    return ans;
  }
};