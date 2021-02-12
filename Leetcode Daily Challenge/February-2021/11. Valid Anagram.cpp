/*
Valid Anagram
=============

Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    vector<int> c1(26, 0), c2(26, 0);
    for (auto &i : s)
      c1[i - 'a']++;
    for (auto &i : t)
      c2[i - 'a']++;
    for (int i = 0; i < 26; ++i)
      if (c1[i] != c2[i])
        return false;
    return true;
  }
};
