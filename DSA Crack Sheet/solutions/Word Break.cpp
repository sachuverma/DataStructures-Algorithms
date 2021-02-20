/*
Word Break
==========

Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words. 

Example 1:
Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" }
A = "ilike"
Output: 1
Explanation:The string can be segmented as "i like".

Example 2:
Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" }
A = "ilikesamsung"
Output: 1
Explanation: The string can be segmented as 
"i like samsung" or "i like sam sung".

Your Task:
Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to break words, else return 0. You don't need to read any input or print any output, it is done by driver code.

Expected time complexity: O(s2)
â€‹Expected auxiliary space: O(s) , where s = length of string A

Constraints:
1 <= N <= 12
1 <= s <=1000 , where s = length of string A
The length of each word is less than 15.
*/

//User function template for C++

// A : given string to search
// B : vector of available strings

int wordBreak(string s, unordered_set<string> &S, unordered_set<string> &memo)
{
  if (memo.find(s) != memo.end())
    return true;
  if (s.size() == 0)
    return 1;
  for (int i = 0; i < s.size(); ++i)
  {
    if (S.find(s.substr(0, i + 1)) != S.end() && wordBreak(s.substr(i + 1), S, memo))
    {
      memo.insert(s);
      return 1;
    }
  }
  return 0;
}

int wordBreak(string A, vector<string> &B)
{
  unordered_set<string> s(B.begin(), B.end()), memo;
  return wordBreak(A, s, memo);
}
