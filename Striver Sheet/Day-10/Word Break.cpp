/*
Word Break
==========

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

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

bool wordBreak(string s, vector<string> &wordDict)
{
  unordered_set<string> dict(wordDict.begin(), wordDict.end());
  if (dict.size() == 0)
    return false;

  vector<bool> dp(s.size() + 1, false);
  dp[0] = true;

  for (int i = 1; i <= s.size(); i++)
  {
    for (int j = i - 1; j >= 0; j--)
    {
      if (dp[j])
      {
        string word = s.substr(j, i - j);
        if (dict.find(word) != dict.end())
        {
          dp[i] = true;
          break; //next i
        }
      }
    }
  }

  return dp[s.size()];
}
