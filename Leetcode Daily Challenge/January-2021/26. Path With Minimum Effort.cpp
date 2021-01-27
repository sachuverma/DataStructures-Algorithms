/*
Path With Minimum Effort
========================

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

Example 3:
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.


Constraints:
rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106

Hint #1  
Consider the grid as a graph, where adjacent cells have an edge with cost of the difference between the cells.

Hint #2  
If you are given threshold k, check if it is possible to go from (0, 0) to (n-1, m-1) using only edges of ≤ k cost.

Hint #3  
Binary search the k value.
*/

class Solution
{
public:
  int minimumEffortPath(vector<vector<int>> &a)
  {
    int n = a.size();
    int m = a[0].size();

    int v[n + 1][m + 1];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        v[i][j] = INT_MAX;
      }
    }
    v[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    int d[5] = {0, -1, 0, 1, 0};
    while (!q.empty())
    {
      pair<int, int> u = q.front();
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        int x = u.first + d[i];
        int y = u.second + d[i + 1];

        if (x < 0 || y < 0 || y >= m || x >= n)
          continue;

        if (v[x][y] <= v[u.first][u.second])
          continue;

        int p = max(v[u.first][u.second], abs(a[x][y] - a[u.first][u.second]));
        v[x][y] = min(p, v[x][y]);
        q.push({x, y});
      }
    }
    return v[n - 1][m - 1];
  }
};
