/*
Number of Matching Subsequences
===============================

Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

Example 1:
Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

Example 2:
Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2

Constraints:
1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
*/

class Solution
{
public:
  bool match(vector<vector<int>> &a, string &b)
  {
    int prev = -1;
    for (int i = 0; i < b.size(); ++i)
    {
      auto pos = upper_bound(a[b[i] - 'a'].begin(), a[b[i] - 'a'].end(), prev);
      if (pos == a[b[i] - 'a'].end())
        return false;
      prev = *pos;
    }
    return true;
  }

  int numMatchingSubseq(string &s, vector<string> &words)
  {
    int ans = 0;
    vector<vector<int>> positions(26, vector<int>(0));

    for (int i = 0; i < s.size(); ++i)
      positions[s[i] - 'a'].push_back(i);

    for (auto &word : words)
    {
      ans += match(positions, word);
    }

    return ans;
  }
};