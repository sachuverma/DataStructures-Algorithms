/*
Implement strStr
================

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Example 3:
Input: haystack = "", needle = ""
Output: 0

Constraints:
0 <= haystack.length, needle.length <= 5 * 104
haystack and needle consist of only lower-case English characters.
*/

class Solution
{
public:
  int strStr(string hs, string n)
  {
    if (n.size() == 0)
      return 0;
    for (int j = 0; j < hs.size(); ++j)
    {
      if (hs[j] == n[0])
      {
        int i = 1;
        while (i < n.size() && hs[j + i] == n[i])
          i++;
        if (i == n.size())
          return j;
      }
    }
    return -1;
  }
};
