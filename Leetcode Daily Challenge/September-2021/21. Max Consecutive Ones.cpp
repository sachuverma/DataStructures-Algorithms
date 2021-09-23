/*
Max Consecutive Ones
====================

Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2
 
Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& A) {
        int ans = 0, i = 0;
        
        while(i < A.size()) {
            
            while(i < A.size() && A[i] != 1) i++;
            
            int count = 0;
            while(i < A.size() && A[i] == 1) {
                i++;
                count++;
            }
            
            ans = max(ans, count);
        }
        
        return ans;
    }
};
