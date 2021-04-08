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
public:
  vector<string> codes = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  void dfs(string digits, int i, string stn, vector<string> &ans)
  {
    if (i == digits.size())
    {
      ans.push_back(stn);
      return;
    }

    auto code = codes[digits[i] - '0'];
    for (auto &e : code)
      dfs(digits, i + 1, stn + e, ans);
  }

  vector<string> letterCombinations(string digits)
  {
    if (!digits.size())
      return {};
    vector<string> ans;
    dfs(digits, 0, "", ans);
    return ans;
  }
};
