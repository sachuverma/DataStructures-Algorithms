/*
Rotten Oranges
==============

Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 

Example 1:
Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.

Example 2:
Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).

Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.

Expected Time Compelxity: O(n*m)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n, m ≤ 500
*/

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int orangesRotting(vector<vector<int>> &grid)
{
  int n = grid.size(), m = grid[0].size();
  int time = 0;
  queue<vector<int>> q;

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
      if (grid[i][j] == 2)
        q.push({i, j});
  }

  while (q.size())
  {
    time++;
    for (int i = q.size(); i > 0; --i)
    {
      auto curr = q.front();
      q.pop();
      int x = curr[0], y = curr[1];
      for (auto &dir : dirs)
      {
        int nx = x + dir[0], ny = y + dir[1];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1)
        {
          grid[nx][ny] = 2;
          q.push({nx, ny});
        }
      }
    }
  }

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      if (grid[i][j] == 1)
        return -1;
    }
  }

  return time - 1;
}
