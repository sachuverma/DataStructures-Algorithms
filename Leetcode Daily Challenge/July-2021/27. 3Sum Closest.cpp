/*
3Sum Closest
============

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 
Constraints:
3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int ans = INT_MIN, diff = INT_MAX;
      sort(nums.begin(), nums.end());
      
      for(int i = 0; i < nums.size(); ++i) {
        int j = i+1, k = nums.size()-1;
        while(j < k) {
          int val = nums[i] + nums[j] + nums[k];
          if(abs(target - val) < diff) {
            ans = val;
            diff = abs(target - val);
          }
          
          if(val < target) j++;
          else k--;
        }
      }
          
      return ans;
    }
};