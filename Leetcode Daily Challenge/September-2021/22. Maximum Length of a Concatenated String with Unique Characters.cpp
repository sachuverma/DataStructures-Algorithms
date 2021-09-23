/*
Maximum Length of a Concatenated String with Unique Characters
==============================================================

Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

Return the maximum possible length of s.

Example 1:
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.

Example 2:
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".

Example 3:
Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
 
Constraints:
1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lower case English letters.
*/

class Solution {
public:
    int dfs(vector<string>& A, int i, vector<int>& masks, int mask) {
        if(i == A.size()) return 0;
        
        int ans = dfs(A, i+1, masks, mask);
        
        if((mask & masks[i]) == 0) {
            mask = mask | masks[i];
            ans = max(ans, (int)A[i].size() + dfs(A, i+1, masks, mask));
        }
        
        return ans;
    }
    
    int maxLength(vector<string>& arr) {
        int mask = 0;
        
        vector<int> masks;
        vector<string> A;
        
        for(auto& a: arr) {
            int curr_mask = 0;
            int flag = 0;
            
            for(auto& e: a) {
                if((curr_mask >> (e - 'a')) & 1) {
                    flag = 1;
                    break;
                }
                curr_mask = curr_mask | (1 << (e-'a'));
            }
            
            if(flag) continue;
            
            A.push_back(a);
            masks.push_back(curr_mask);
        }
        
        return dfs(A, 0, masks, mask);
    }
};

