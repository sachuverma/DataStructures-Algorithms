/*
Palindrome Pairs
================

Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list, so that the concatenation of the two words words[i] + words[j] is a palindrome.

Example 1:
Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]

Example 2:
Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]

Example 3:
Input: words = ["a",""]
Output: [[0,1],[1,0]]

Constraints:
1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] consists of lower-case English letters.
*/

class Solution
{
public:
  bool palendrome(string str)
  {
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
      if (str[i++] != str[j--])
        return false;
    }
    return true;
  }

  vector<vector<int>> palindromePairs(vector<string> &arr)
  {
    unordered_map<string, int> words;
    vector<vector<int>> ans;
    vector<bool> isPal(arr.size(), 0);

    for (int i = 0; i < arr.size(); ++i)
      isPal[i] = palendrome(arr[i]);

    for (int i = 0; i < arr.size(); ++i)
      words[arr[i]] = i;

    for (int i = 0; i < arr.size(); ++i)
    {
      // first type, right me add krke palendrome bnao
      // ie, we have to find prefix ka reverse
      string curr = "";
      for (int j = 0; j < arr[i].size(); ++j)
      {
        curr = arr[i][j] + curr;
        if (words.count(curr) && words[curr] != i && palendrome(arr[i] + curr))
        {
          ans.push_back({i, words[curr]});
        }
      }

      // phir suffix ka reverse dekhna hai
      curr = "";
      for (int j = arr[i].size() - 1; j > 0; --j)
      {
        curr += arr[i][j];
        if (words.count(curr) && words[curr] != i && palendrome(curr + arr[i]))
        {
          ans.push_back({words[curr], i});
        }
      }
    }

    // match empty string with all palendromes
    for (int i = 0; i < arr.size(); ++i)
    {
      if (arr[i] == "")
      {
        for (int j = 0; j < arr.size(); ++j)
        {
          if (i != j && isPal[j])
          {
            ans.push_back({i, j});
            ans.push_back({j, i});
          }
        }
      }
    }

    return ans;
  }
};
