/*
Combination Sum II
==================

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

Constraints:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

class Solution
{
public:
  void dfs(vector<int> &arr, int i, int tar, vector<int> atn, vector<vector<int>> &ans)
  {
    if (tar < 0)
      return;
    if (tar == 0)
    {
      ans.push_back(atn);
      return;
    }

    for (int j = i; j < arr.size(); ++j)
    {
      if (j != i && arr[j] == arr[j - 1])
        continue;
      atn.push_back(arr[j]);
      dfs(arr, j + 1, tar - arr[j], atn, ans);
      atn.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &arr, int target)
  {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    dfs(arr, 0, target, {}, ans);
    return ans;
  }
};
