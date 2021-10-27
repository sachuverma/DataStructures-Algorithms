/*
Summary Ranges
==============

[Problem]
You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:
 - "a->b" if a != b
 - "a" if a == b


[Example 1]
 Input: nums = [0,1,2,4,5,7]
 Output: ["0->2","4->5","7"]
 Explanation: The ranges are:
  [0,2] --> "0->2"
  [4,5] --> "4->5"
  [7,7] --> "7"


[Example 2]
 Input: nums = [0,2,3,4,6,8,9]
 Output: ["0","2->4","6","8->9"]
 Explanation: The ranges are:
  [0,0] --> "0"
  [2,4] --> "2->4"
  [6,6] --> "6"
  [8,9] --> "8->9"

[Constraints]
 * 0 <= nums.length <= 20
 * -231 <= nums[i] <= 231 - 1
 * All the values of nums are unique.
 * nums is sorted in ascending order.

*/

class Solution {
public:
	// check the difference b/w the number
	// if the difference is 1 append that to same array
	// else start new set of array
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 ) return {};
        
        vector<vector<string > > ans;
        ans.push_back({to_string(nums[0])});
        for(int i=1; i<n; i++) {
            if(nums[i]*1LL - nums[i-1]*1LL == 1LL) {
                if(ans.back().size() != 1) {
                    ans.back().pop_back();
                }
                ans.back().push_back(to_string(nums[i]));
            } else {
                ans.push_back({to_string(nums[i])});
            }
        }
        
        vector<string > res;
        for(auto x: ans) {
            string temp;
            for(auto y: x) {
                temp += y + "->";
            }
            temp.pop_back();
            temp.pop_back();
            res.push_back(temp);
        }
        
        return res;
    }
};