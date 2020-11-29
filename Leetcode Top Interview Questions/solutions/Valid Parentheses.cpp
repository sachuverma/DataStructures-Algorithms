/*
Valid Parentheses
=================

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([)]"
Output: false

Example 5:
Input: s = "{[]}"
Output: true
 

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

Hint #1  
An interesting property about a valid parenthesis expression is that a sub-expression of a valid expression should also be a valid expression. (Not every sub-expression) e.g.
{ { } [ ] [ [ [ ] ] ] } is VALID expression
          [ [ [ ] ] ]    is VALID sub-expression
  { } [ ]                is VALID sub-expression
Can we exploit this recursive structure somehow?

Hint #2  
What if whenever we encounter a matching pair of parenthesis in the expression, we simply remove it from the expression? This would keep on shortening the expression. e.g.
{ { ( { } ) } }
      |_|

{ { (      ) } }
    |______|

{ {          } }
  |__________|

{                }
|________________|

VALID EXPRESSION!

Hint #3  
The stack data structure can come in handy here in representing this recursive structure of the problem. We can't really process this from the inside out because we don't have an idea about the overall structure. But, the stack can help us process this recursively i.e. from outside to inwards.
*/

class Solution
{
public:
  bool isValid(string str)
  {
    stack<char> s;
    for (auto ch : str)
    {
      if (ch == '(' || ch == '[' || ch == '{')
        s.push(ch);
      else
      {
        if (s.size() == 0)
          return false;
        if (ch == ')')
        {
          if (s.top() == '(')
            s.pop();
          else
            return false;
        }
        else if (ch == ']')
        {
          if (s.top() == '[')
            s.pop();
          else
            return false;
        }
        else if (ch == '}')
        {
          if (s.top() == '{')
            s.pop();
          else
            return false;
        }
      }
    }

    return s.size() == 0;
  }
};
