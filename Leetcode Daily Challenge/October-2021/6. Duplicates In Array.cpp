
/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, 
return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:
Input: nums = [1,1,2]
Output: [1] 
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp; 
        
        for(int i = 0 ; i < nums.size(); i++){
            if(mp.find(nums[i])!= mp.end()){
                mp[nums[i]]++;
            }
            else{
                mp.insert({nums[i],1}); 
            }
        }
        vector<int>ans; 
        for(auto it : mp){
            if(it.second == 2){
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};
