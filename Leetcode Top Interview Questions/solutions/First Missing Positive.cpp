/*
Given an unsorted integer array nums, return the smallest missing positive integer.
You must implement an algorithm that runs in O(n) time and uses constant extra space.

Example 1:
Input: nums = [1,2,0]
Output: 3

Example 2:
Input: nums = [3,4,-1,1]
Output: 2

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1

Constraints:
1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1

*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int i=1;
        while(i<=nums.size()){
            if(nums[i-1]!=i && nums[i-1]>=1 && nums[i-1]<=nums.size()){
                if(nums[nums[i-1]-1]==nums[i-1] || nums[i-1]==0){
                    i++;
                    continue;
                }
                swap(nums[nums[i-1]-1],nums[i-1]);
            }
            else
                i++;
        }
        for(int i=1;i<=nums.size();i++){
            if(i!=nums[i-1])
                return i;
        }
        return nums.size()+1;       
    }
};