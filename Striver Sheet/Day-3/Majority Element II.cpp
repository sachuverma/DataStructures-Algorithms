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
    vector<int> elem(2, -1000000001);
    vector<int> count(2, 0);

    int n = nums.size();
    for (auto &i : nums)
    {
      if (elem[0] == i)
        count[0]++;
      else if (elem[1] == i)
        count[1]++;
      else if (count[0] == 0)
      {
        elem[0] = i;
        count[0]++;
      }
      else if (count[1] == 0)
      {
        elem[1] = i;
        count[1]++;
      }
      else
      {
        count[0]--;
        count[1]--;
      }
    }

    count[0] = 0;
    count[1] = 0;
    for (auto &i : nums)
    {
      if (i == elem[0])
        count[0]++;
      if (i == elem[1])
        count[1]++;
    }

    vector<int> ans;
    if (count[0] > n / 3)
      ans.push_back(elem[0]);
    if (count[1] > n / 3)
      ans.push_back(elem[1]);
    return ans;
  }
};
