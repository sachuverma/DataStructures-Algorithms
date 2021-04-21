/*
Reverse a string using Stack
============================

You are given a string S, the task is to reverse the string using stack.

Example 1:
Input: S="GeeksforGeeks"
Output: skeeGrofskeeG

Your Task:
You don't need to read input or print anything. Your task is to complete the function reverse() which takes the string S as an input parameter and returns the reversed string.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ length of the string ≤ 100
*/

char *reverse(char *S, int len)
{
  char *ans = new char[len + 1];
  stack<char> st;
  for (int i = 0; i < len && S[i] != '\0'; ++i)
    st.push(S[i]);
  int i;
  for (i = 0; i < len; ++i)
  {
    ans[i] = st.top();
    st.pop();
  }
  ans[i] = '\0';
  return ans;
}
