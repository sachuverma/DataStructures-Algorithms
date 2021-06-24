/*
Out of Boundary Paths
=====================

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent four cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

Example 1:
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

Example 2:
Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12

Constraints:
1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow <= m
0 <= startColumn <= n

Hint #1  
WIll traversing every path is fesaible? There are many possible paths for a small matrix. Try to optimize it.

Hint #2  
Can we use some space to store the number of paths and updating them after every move?

Hint #3  
One obvious thing: ball will go out of boundary only by crossing it. Also, there is only one possible way ball can go out of boundary from boundary cell except corner cells. From corner cell ball can go out in two different ways. Can you use this thing to solve the problem?
*/

class Solution
{
public:
  long M = 1e9 + 7;

  long dfs(int r, int c, int m, int n, int k, long memo[51][51][51])
  {
    if (r < 0 || c < 0 || r >= m || c >= n)
      return 1;
    if (k == 0)
      return 0;

    if (memo[r][c][k] != -1)
      return memo[r][c][k];

    long ans = 0;
    ans = (dfs(r + 1, c, m, n, k - 1, memo) % M + dfs(r, c + 1, m, n, k - 1, memo) % M + dfs(r - 1, c, m, n, k - 1, memo) % M + dfs(r, c - 1, m, n, k - 1, memo) % M) % M;

    return memo[r][c][k] = ans;
  }

  int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
  {
    long memo[51][51][51];
    memset(memo, -1, sizeof memo);
    return dfs(startRow, startColumn, m, n, maxMove, memo);
  }
};
