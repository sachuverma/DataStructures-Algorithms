/*
Evaluate Reverse Polish Notation
================================

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

Constraints:
1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/

class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    stack<long> st;
    for (auto &i : tokens)
    {

      if ((i[0] >= '0' && i[0] <= '9') ||
          (i[0] == '-' && i[1] >= '0' && i[1] <= '9') ||
          (i[0] == '+' && i[1] >= '0' && i[1] <= '9'))
        st.push(stoi(i));

      else
      {
        long num2 = st.top();
        st.pop();
        long num1 = st.top();
        st.pop();
        long res = 0;

        if (i == "+")
          res = num1 + num2;
        else if (i == "-")
          res = num1 - num2;
        else if (i == "*")
          res = num1 * num2;
        else
          res = num1 / num2;

        st.push(res);
      }
    }
    return st.top();
  }
};
