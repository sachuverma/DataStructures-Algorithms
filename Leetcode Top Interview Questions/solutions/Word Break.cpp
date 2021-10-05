/*Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = s.size();
        unordered_map<string, bool> x;
        for(string s : wordDict){
            x[s] = true;
        }
        vector<bool> dp(n);
        for(int i = 0;i<n;i++){
            if(x[s.substr(0, i + 1)]){
                dp[i] = true;
            }
            else{
                for(int j = 0;j<i;j++){
                    if(x[s.substr(j + 1, (i - (j + 1) + 1))] && dp[j] == true){
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
