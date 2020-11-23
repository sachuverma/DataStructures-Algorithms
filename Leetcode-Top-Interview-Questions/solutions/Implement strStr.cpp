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
  int strStr(string haystack, string needle)
  {
    int n = haystack.size();
    int needle_len = needle.size();

    if (!needle_len)
      return 0;

    for (int i = 0; i < n; ++i)
    {
      if (haystack[i] == needle[0] && i + needle_len <= n)
      {
        if (haystack.substr(i, needle_len) == needle)
          return i;
        else
          continue;
      }
    }
    return -1;
  }
};