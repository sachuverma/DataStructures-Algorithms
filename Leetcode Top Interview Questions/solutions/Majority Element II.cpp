/*
Majority Element II
===================

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Follow-up: Could you solve the problem in linear time and in O(1) space?

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]

Constraints:
1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
*/

class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    vector<int> ans;
    sort(nums.begin(), nums.end());

    int i = 0;
    while (i < nums.size())
    {
      int up = upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
      int low = lower_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
      if (up - low > nums.size() / 3)
        ans.push_back(nums[i]);

      i = up;
    }

    return ans;
  }
};
