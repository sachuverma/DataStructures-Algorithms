/*
Letter Case Permutation
=======================

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

Example 1:
Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:
Input: S = "3z4"
Output: ["3z4","3Z4"]

Example 3:
Input: S = "12345"
Output: ["12345"]

Example 4:
Input: S = "0"
Output: ["0"]

Constraints:
S will be a string with length between 1 and 12.
S will consist only of letters or digits.
*/

class Solution
{
public:
  void recurse(string s, int curr, vector<string> &ans)
  {
    if (curr == s.size())
    {
      ans.push_back(s);
      return;
    }

    if (isalpha(s[curr]))
    {
      string n1 = s, n2 = s;
      n1[curr] = toupper(n1[curr]);
      n2[curr] = tolower(n2[curr]);
      recurse(n2, curr + 1, ans);
      recurse(n1, curr + 1, ans);
    }
    else
    {
      recurse(s, curr + 1, ans);
    }
  }

  vector<string> letterCasePermutation(string S)
  {
    vector<string> ans;
    recurse(S, 0, ans);
    return ans;
  }
};
