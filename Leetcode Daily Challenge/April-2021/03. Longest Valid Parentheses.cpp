/*
Longest Valid Parentheses
=========================

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0

Constraints:
0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/

class Solution
{
public:
  int longestValidParentheses(string s)
  {
    int ans = 0;
    stack<char> sc;
    stack<int> si;
    si.push(-1);

    for (int i = 0; i < s.size(); ++i)
    {
      char ch = s[i];
      if (ch == ')')
      {
        if (sc.size() && sc.top() == '(')
        {
          sc.pop();
          si.pop();

          int curr = i - si.top();
          //  si.push(i);
          ans = max(ans, curr);
        }
        else
          si.push(i);
      }
      else
      {
        sc.push(ch);
        si.push(i);
      }
    }

    return ans;
  }
};
