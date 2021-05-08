/*
Valid Anagram
==============

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    vector<int> arr(26, 0);
    for (auto &i : s)
      arr[i - 'a']++;
    for (auto &i : t)
      arr[i - 'a']--;
    for (auto &i : arr)
      if (i != 0)
        return false;
    return true;
  }
};
