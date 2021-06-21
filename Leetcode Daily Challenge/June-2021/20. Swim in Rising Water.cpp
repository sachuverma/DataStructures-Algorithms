/*
Swim in Rising Water
====================

On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

Example 1:
Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.

Example 2:
Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
Note:

2 <= N <= 50.
grid[i][j] is a permutation of [0, ..., N*N - 1].

Hint #1  
Use either Dijkstra's, or binary search for the best time T for which you can reach the end if you only step on squares at most T.
*/

class Solution
{
public:
  int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  int swimInWater(vector<vector<int>> &grid)
  {
    int t = 0, n = grid.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    pq.push({grid[0][0], 0, 0});
    grid[0][0] = -1;

    while (pq.size())
    {
      while (pq.size() && pq.top()[0] <= t)
      {
        auto curr = pq.top();
        pq.pop();

        int x = curr[1], y = curr[2];
        if (x == n - 1 && y == n - 1)
          return t;

        for (auto &dir : dirs)
        {
          int nx = x + dir[0], ny = y + dir[1];
          if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] != -1)
          {
            pq.push({grid[nx][ny], nx, ny});
            grid[nx][ny] = -1;
          }
        }
      }
      t++;
    }

    return -1;
  }
};
