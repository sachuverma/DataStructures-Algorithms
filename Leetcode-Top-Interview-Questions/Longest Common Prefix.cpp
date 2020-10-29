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
    if (strs.size() == 0)
      return "";

    string ans = "";
    int min_len = INT_MAX, i = 0;
    for (auto &ch : strs)
      min_len = min(min_len, (int)ch.size());

    for (i = 0; i < min_len; i++)
    {
      char ch;
      int flag = 0;

      for (int j = 0; j < strs.size(); ++j)
      {
        if (j == 0)
          ch = strs[j][i];
        else
        {
          if (strs[j][i] != ch)
          {
            flag = 1;
            break;
          }
        }
      }

      if (flag)
        break;
    }

    ans = strs[0].substr(0, i);
    return ans;
  }
};
