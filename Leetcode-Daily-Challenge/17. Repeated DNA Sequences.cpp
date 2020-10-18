/*
Repeated DNA Sequences
======================

All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.


Example 1:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

Example 2:
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]

Constraints:

0 <= s.length <= 105
s[i] is 'A', 'C', 'G', or 'T'.

*/

class Solution
{
public:
  vector<string> findRepeatedDnaSequences(string s)
  {
    if (s.size() < 10)
      return {};
    unordered_map<string, int> m;
    vector<string> ans;

    for (int i = 0; i <= s.size() - 10; ++i)
    {
      string subStr = s.substr(i, 10);
      m[subStr]++;
    }

    for (auto it = m.begin(); it != m.end(); ++it)
    {
      cout << it->first << " " << it->second << endl;
      if (it->second > 1)
        ans.push_back(it->first);
    }

    return ans;
  }
};
