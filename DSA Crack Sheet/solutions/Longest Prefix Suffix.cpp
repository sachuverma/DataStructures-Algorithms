/*
Longest Prefix Suffix
=====================

Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

Example 1:
Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper 
prefix and suffix. 

Example 2:
Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper 
prefix and suffix. 
Your task:
You do not need to read any input or print anything. The task is to complete the function lps(), which takes a string as input and returns an integer.

Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |s| ≤ 105
s contains lower case English alphabets
*/

int lps(string s)
{
  int n = s.size(), len = 0;
  vector<int> lps(n, 0);
  lps[0] = 0;

  int i = 1;
  while (i < n)
  {
    if (s[i] == s[len])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else
    {
      if (len != 0)
        len = lps[len - 1];
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps[n - 1];
}
