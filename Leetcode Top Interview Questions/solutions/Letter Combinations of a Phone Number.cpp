/*
Letter Combinations of a Phone Number
=====================================

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution
{
  vector<string> key = {
      "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
      // 0   1    2      3      4      5      6       7      8       9
  };

  void pattern(vector<string> &ans, int i, string s, string out = "")
  {
    if (i >= s.size())
    {
      if (out.size())
        ans.push_back(out);
      return;
    }

    int digit = s[i] - '0';
    for (int j = 0; j < key[digit].size(); ++j)
      pattern(ans, i + 1, s, out + key[digit][j]);
  }

public:
  vector<string> letterCombinations(string digits)
  {
    vector<string> ans;
    pattern(ans, 0, digits);
    return ans;
  }
};
