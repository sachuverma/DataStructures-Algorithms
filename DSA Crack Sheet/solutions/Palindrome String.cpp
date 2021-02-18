/*
Palindrome String
=================

Given a string S, check if it is palindrome or not.

Example 1:
Input: S = "abba"
Output: 1
Explanation: S is a palindrome

Example 2:
Input: S = "abc" 
Output: 0
Explanation: S is not a palindrome

Your Task:  
You don't need to read input or print anything. Complete the function isPlaindrome() which accepts string S and returns a boolean value

Expected Time Complexity: O(Length of S) 
Expected Auxiliary Space: O(1) 

Constraints:
1 <= Length of S <= 105
*/

int isPlaindrome(string s)
{
  for (int i = 0; i < s.size() / 2; ++i)
  {
    if (s[i] != s[s.size() - 1 - i])
      return 0;
  }
  return 1;
}
