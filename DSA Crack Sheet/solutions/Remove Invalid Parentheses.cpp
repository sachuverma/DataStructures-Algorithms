/*
Remove Invalid Parentheses
==========================

Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.

Example 1:
Input: s = "()())()"
Output: ["(())()","()()()"]

Example 2:
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]

Example 3:
Input: s = ")("
Output: [""]

Constraints:
1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.
There will be at most 20 parentheses in s.
*/

class Solution {
public:
    unordered_set<string> ans;
    int rems;
  
    void dfs(string &s, int i, int o, int c, int r, string curr){
      if(i == s.size()) {
        if(o != c) return;
        
        if(r < rems) {
          rems = r;
          ans.clear();
        }
        
        if(r == rems) ans.insert(curr);
        return;
      }    
      
      if(s[i] == '('){
        dfs(s, i+1, o, c, r+1, curr);
        dfs(s, i+1, o+1, c, r, curr + "(");
      }
      else if(s[i] == ')'){
        if(c < o) 
          dfs(s, i+1, o, c+1, r, curr + ")");
        dfs(s, i+1, o, c, r+1, curr);
      }
      else {
        curr += s[i];
        dfs(s, i+1, o, c, r, curr);
      }
    }
  
    vector<string> removeInvalidParentheses(string s) {
      ans = unordered_set<string>(0);
      rems = s.size();
      
      dfs(s, 0, 0, 0, 0, "");
      
      vector<string> vans;
      for(auto &i: ans) vans.push_back(i);
      return vans;
    }
};
