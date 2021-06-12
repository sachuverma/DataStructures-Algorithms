/*
The Celebrity Problem
======================

A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.

Example 1:
Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 

Example 2:
Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.

Your Task:
You don't need to read input or print anything. Complete the function celebrity() which takes the matrix M and its size N as input parameters and returns the index of the celebrity. If no such celebrity is present, return -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
2 <= N <= 3000
0 <= M[][] <= 1
*/

int celebrity(vector<vector<int>> &M, int n)
{
  stack<int> st;
  for (int i = 0; i < n; ++i)
    st.push(i);

  while (st.size() > 1)
  {
    int i = st.top();
    st.pop();
    int j = st.top();
    st.pop();

    if (M[i][j] && M[j][i])
      continue;
    else if (M[i][j])
      st.push(j);
    else if (M[j][i])
      st.push(i);
    else // dono ek dusre ko nhi jate toh bhi celebrity nhi honge koisa bhi
      continue;
  }

  if (st.size())
  {
    int c = st.top();
    int a = 0, b = 0;

    for (int i = 0; i < n; ++i)
    {
      if (M[i][c])
        a++;
      if (M[c][i])
        b++;
    }

    if (a == n - 1 && b == 0)
      return c;
  }

  return -1;
}
