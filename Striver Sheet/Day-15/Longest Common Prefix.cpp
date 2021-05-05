/*
Longest Common Prefix
=====================

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    string ans;
    int minLen = INT_MAX;
    for (auto &i : strs)
      minLen = min(minLen, (int)i.size());
    for (int i = 0; i < minLen; ++i)
    {
      int ch = strs[0][i];
      for (int j = 1; j < strs.size(); ++j)
      {
        if (strs[j][i] != ch)
          return ans;
      }
      ans += ch;
    }
    return ans;
  }
};
