/*
Remove Duplicate Letters
========================

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/



Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"


Constraints:
1 <= s.length <= 104
s consists of lowercase English letters.

Hide Hint #1  
Greedily try to add one missing character. How to check if adding some character will not cause problems ? Use bit-masks to check whether you will be able to complete the sub-sequence if you add the character at some index i.
*/

class Solution
{
public:
  string removeDuplicateLetters(string s)
  {
    stack<char> st;
    vector<bool> taken(26, false);
    vector<int> lastIndex(26, -1);
    for (int i = 0; i < s.size(); ++i)
      lastIndex[s[i] - 'a'] = i;

    for (int i = 0; i < s.size(); ++i)
    {
      if (taken[s[i] - 'a'] == true)
        continue;

      if (st.empty())
      {
        st.push(s[i]);
        taken[s[i] - 'a'] = true;
      }
      else
      {
        while (st.size() && s[i] < st.top() && i < lastIndex[st.top() - 'a'])
        {
          taken[st.top() - 'a'] = false;
          st.pop();
        }
        st.push(s[i]);
        taken[s[i] - 'a'] = true;
      }
    }

    string ans;
    while (st.size())
    {
      char te = st.top();
      ans = te + ans;
      st.pop();
    }

    return ans;
  }
};