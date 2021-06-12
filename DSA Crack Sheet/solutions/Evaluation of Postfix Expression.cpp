/*
Evaluation of Postfix Expression
================================

Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

Example 1:
Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression, 
we have -4 as result.

Example 2:
Input: S = "123+*8-"
Output: -3
Explanation:
After solving the given postfix 
expression, we have -3 as result.

Your Task:
You do not need to read input or print anything. Complete the function evaluatePostfixExpression() that takes the string S denoting the expression as input parameter and returns the evaluated value.

Expected Time Complexity: O(|S|)
Expected Auixilliary Space: O(|S|)

Constraints:
1 ≤ |S| ≤ 105
*/

int evaluatePostfix(string S)
{
  stack<int> st;
  for (auto &i : S)
  {
    if (i >= '0' && i <= '9')
      st.push(i - '0');
    else
    {
      int f = st.top();
      st.pop();
      int s = st.top();
      st.pop();
      if (i == '+')
        st.push(s + f);
      else if (i == '-')
        st.push(s - f);
      else if (i == '*')
        st.push(s * f);
      else if (i == '/')
        st.push(s / f);
    }
  }
  return st.top();
}
