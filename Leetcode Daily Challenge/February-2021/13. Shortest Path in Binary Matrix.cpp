/*
Shortest Path in Binary Matrix
==============================

In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

Example 1:
Input: [[0,1],[1,0]]
Output: 2

Example 2:
Input: [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Note:
1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1

Hint #1  
Do a breadth first search to find the shortest path.

*/

class Solution
{
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid)
  {
    if (grid[0][0] == 1)
      return -1;

    int n = grid.size();
    queue<vector<int>> pending;
    pending.push({0, 0});
    grid[0][0] = 1;

    int ans = INT_MAX;
    int steps = 0;

    int dir[] = {-1, 0, 1};

    while (pending.size())
    {
      auto size = pending.size();

      for (int i = 0; i < size; ++i)
      {
        auto curr = pending.front();
        pending.pop();
        int x = curr[0], y = curr[1];

        if (x == n - 1 && y == n - 1)
        {
          steps++;
          ans = min(ans, steps);
          continue;
        }

        for (int j = 0; j < 3; ++j)
        {
          for (int l = 0; l < 3; ++l)
          {

            int nextX = x + dir[j];
            int nextY = y + dir[l];

            if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= n || (nextX == x && nextY == y) || grid[nextX][nextY])
            {
              continue;
            }
            else
            {
              grid[nextX][nextY] = 1;
              pending.push({nextX, nextY});
            }
          }
        }
      }
      steps++;
    }

    return ans != INT_MAX ? ans : -1;
  }
};
