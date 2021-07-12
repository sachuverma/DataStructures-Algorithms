/*
Isomorphic Strings
==================

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true

Constraints:
1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    unordered_map<char, char> Map;
    unordered_set<char> mapped;

    if (s.size() != t.size())
      return false;

    for (int i = 0; i < s.size(); ++i)
    {
      int cs = s[i], ct = t[i];
      if (Map.count(cs))
      {
        if (Map[cs] == ct)
          continue;
        else
          return false;
      }
      else
      {
        if (mapped.count(ct))
          return false;
        Map[cs] = ct;
        mapped.insert(ct);
      }
    }
    return true;
  }
};