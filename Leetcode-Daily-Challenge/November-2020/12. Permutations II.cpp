/*
Permutations II
===============

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


Constraints:
1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

class Solution
{
public:
  vector<vector<int>> permuteUnique(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    do
    {
      ans.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return ans;
  }
};
