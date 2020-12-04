/*
Partition Labels
================

A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

Note:
S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.
*/

class Solution
{
public:
  vector<int> partitionLabels(string S)
  {
    vector<int> ans, lastIndex(26, 0);
    for (int i = 0; i < S.size(); ++i)
      lastIndex[S[i] - 'a'] = i;

    int i = 0;
    while (i < S.size())
    {
      int end = lastIndex[S[i] - 'a'];
      int j = i;
      while (j != end)
        end = max(end, lastIndex[S[j++] - 'a']);
      ans.push_back(j - i + 1);
      i = j + 1;
    }
    return ans;
  }
};
