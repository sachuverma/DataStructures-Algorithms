/*
Longest Consecutive Sequence
============================

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
0 <= nums.length <= 104
-109 <= nums[i] <= 109

Follow up: Could you implement the O(n) solution?
*/

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    int n = nums.size();
    if (n <= 1)
      return n;

    int ans = 1;
    unordered_set<int> s;
    for (auto &i : nums)
      s.insert(i);

    for (auto &i : nums)
    {
      if (s.find(i - 1) != s.end())
        continue;
      int num = i;
      int count = 1;
      while (s.find(num + 1) != s.end())
      {
        count++;
        num = num + 1;
      }
      ans = max(ans, count);
    }
    return ans;
  }
};
