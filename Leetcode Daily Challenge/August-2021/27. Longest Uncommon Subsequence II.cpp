/*
Longest Uncommon Subsequence II
===============================

Given an array of strings strs, return the length of the longest uncommon subsequence between them. If the longest uncommon subsequence does not exist, return -1.

An uncommon subsequence between an array of strings is a string that is a subsequence of one string but not the others.

A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.

For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).

Example 1:
Input: strs = ["aba","cdc","eae"]
Output: 3

Example 2:
Input: strs = ["aaa","aaa","aa"]
Output: -1

Constraints:
1 <= strs.length <= 50
1 <= strs[i].length <= 10
strs[i] consists of lowercase English letters.
*/

class Solution {
public:
    bool isSubseq(string& a, string& b) {
        int ia = 0, ib = 0;
        while(ia < a.size() && ib < b.size()) {
            if(a[ia] == b[ib]) {
                ia++;
                ib++;
            }
            else ib++;
        }
        
        return ia == a.size();
    }
    
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        
        for(int i = 0; i < strs.size(); ++i) {
            int flag = 0;
            for(int j = 0; j < strs.size(); ++j) {
                if(i != j && isSubseq(strs[i], strs[j])) {
                    flag = 1;
                    break;
                }
            }
            
            if(!flag) ans = max(ans, (int)strs[i].size());
        }
        
        return ans;
    }
};

