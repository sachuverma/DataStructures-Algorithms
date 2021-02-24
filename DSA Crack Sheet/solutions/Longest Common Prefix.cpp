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
0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    if (!strs.size())
      return "";
    string ans = strs[0];

    for (auto &word : strs)
    {
      int i = 0, j = 0, flag = 1;

      while (i < ans.size() && j < word.size())
      {
        if (ans[i] == word[j])
        {
          i++;
          j++;
        }
        else
        {
          flag++;
          break;
        }
      }

      if (!flag && i == 0)
        return "";
      ans = ans.substr(0, i);
    }

    return ans;
  }
};
