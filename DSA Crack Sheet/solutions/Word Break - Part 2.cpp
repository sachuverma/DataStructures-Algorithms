/*
Word Break - Part 2
===================

Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. Each dictionary word can be used more than once. Return all such possible sentences.

Follow examples for better understanding.

Example 1:
Input: s = "catsanddog", n = 5 
dict = {"cats", "cat", "and", "sand", "dog"}
Output: (cats and dog)(cat sand dog)
Explanation: All the words in the given 
sentences are present in the dictionary.

Example 2:
Input: s = "catsandog", n = 5
dict = {"cats", "cat", "and", "sand", "dog"}
Output: Empty
Explanation: There is no possible breaking 
of the string s where all the words are present in dict.

Your Task:
You do not need to read input or print anything. Your task is to complete the function wordBreak() which takes n, dict and s as input parameters and returns a list of possible sentences. If no sentence is possible it returns an empty list.

Expected Time Complexity: O(N2*n) where N = |s|
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ n ≤ 20
1 ≤ dict[i] ≤ 15
1 ≤ |s| ≤ 500 
*/

class Solution
{
public:
  void dfs(int n, unordered_set<string> &dict, string s, int i, vector<string> &ans, string sent, string wrd)
  {
    if (i > s.size())
      return;
    if (dict.find(wrd) != dict.end())
    {
      if (i == s.size())
      {
        sent += wrd;
        ans.push_back(sent);
        return;
      }
      else
      {
        dfs(n, dict, s, i + 1, ans, sent, wrd + s[i]);
        sent += wrd + " ";
        dfs(n, dict, s, i, ans, sent, "");
      }
    }
    else
    {
      if (i == s.size())
        return;
      wrd += s[i];
      dfs(n, dict, s, i + 1, ans, sent, wrd);
    }
  }
  vector<string> wordBreak(int n, vector<string> &dict, string s)
  {
    unordered_set<string> dic(dict.begin(), dict.end());
    vector<string> ans;
    dfs(n, dic, s, 0, ans, "", "");
    return ans;
  }
};
