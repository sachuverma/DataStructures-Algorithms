/*
Palindrome Partitioning II
==========================

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:
Input: s = "a"
Output: 0

Example 3:
Input: s = "ab"
Output: 1
 
Constraints:
1 <= s.length <= 2000
s consists of lower-case English letters only.
*/

class Solution {
public:
    vector<int> memo;
    
    bool palendrome(string& s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }    
        return true;
    }
    
    int dfs(int i, string& s) {
        if(i == s.size()) return 0;
        
        if(memo[i] != -1) return memo[i];
        
        int ans = s.size();
        for(int j = i; j < s.size(); ++j) {
            if(palendrome(s, i, j)) {
                ans = min(ans, 1 + dfs(j+1, s));
            }
        }
        
        return memo[i] = ans;
    }
    
    int minCut(string s) {
        memo = vector<int> (s.size()+1, -1);
        return dfs(0, s) - 1;
    }
};