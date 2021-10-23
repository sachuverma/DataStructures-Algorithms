/*
Next Permutation
================

[Problem]
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
The replacement must be in place and use only constant extra memory.

[Example 1]
Input: nums = [1,2,3]
Output: [1,3,2]


[Example 2]
Input: nums = [3,2,1]
Output: [1,2,3]


[Constraints]
1 <= nums.length <= 100
0 <= nums[i] <= 100
*/

class Solution {
public:
    // find first number from the last which is not increasing
    // i.e A[i] < A[i+1] then sort the array after A[i] in increasing order
    // swap A[i] with it's next greater number we have our answer
    void nextPermutation(vector<int>& nums) {
        int N = nums.size();
        int id = -1;
        for(int i=N-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                id = i;
                break;
            }
        }
        
        // it is already decreasing order
        reverse(nums.begin() + id + 1, nums.end());
        
        // we have whole array as decreasing
        if(id == -1) return;
        
        auto it = upper_bound(nums.begin() + id + 1, nums.end(), nums[id]);
        swap(nums[id], *it);
        
        return;
    }
};