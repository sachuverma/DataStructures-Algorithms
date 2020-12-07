/*
Cut Off Trees for Golf Event
============================

You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an m x n matrix. In this matrix:

0 means the cell cannot be walked through.
1 represents an empty cell that can be walked through.
A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.
In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.

You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes 1 (an empty cell).

Starting from the point (0, 0), return the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1.

You are guaranteed that no two trees have the same height, and there is at least one tree needs to be cut off.

Example 1:
Input: forest = [[1,2,3],[0,0,4],[7,6,5]]
Output: 6
Explanation: Following the path above allows you to cut off the trees from shortest to tallest in 6 steps.

Example 2:
Input: forest = [[1,2,3],[0,0,0],[7,6,5]]
Output: -1
Explanation: The trees in the bottom row cannot be accessed as the middle row is blocked.

Example 3:
Input: forest = [[2,3,4],[0,0,5],[8,7,6]]
Output: 6
Explanation: You can follow the same path as Example 1 to cut off all the trees.
Note that you can cut off the first tree at (0, 0) before making any steps.

Constraints:
m == forest.length
n == forest[i].length
1 <= m, n <= 50
0 <= forest[i][j] <= 109
*/

class Solution
{
public:
  int cutOffTree(vector<vector<int>> &forest)
  {
    if (forest.empty() || forest[0].empty())
      return 0;
    int m = forest.size(), n = forest[0].size();
    vector<vector<int>> trees;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (forest[i][j] > 1)
          trees.push_back({forest[i][j], i, j});
      }
    }
    sort(trees.begin(), trees.end());
    int ans = 0;

    for (int i = 0, cur_row = 0, cur_col = 0; i < trees.size(); i++)
    {
      int step = next_step(forest, cur_row, cur_col, trees[i][1], trees[i][2]);

      if (step == -1)
        return -1;
      ans += step;
      cur_row = trees[i][1];
      cur_col = trees[i][2];
    }
    return ans;
  }

private:
  int next_step(vector<vector<int>> &forest, int sr, int sc, int er, int ec)
  {
    if (sr == er && sc == ec)
      return 0;
    int m = forest.size(), n = forest[0].size();
    queue<pair<int, int>> myq;
    myq.push({sr, sc});
    vector<vector<int>> visited(m, vector<int>(n, 0));
    visited[sr][sc] = 1;
    int step = 0;
    vector<int> dir = {-1, 0, 1, 0, -1};
    while (!myq.empty())
    {
      step++;
      int sz = myq.size();
      for (int i = 0; i < sz; i++)
      {
        int row = myq.front().first, col = myq.front().second;
        myq.pop();
        for (int i = 0; i < 4; i++)
        {
          int r = row + dir[i], c = col + dir[i + 1];
          if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == 1 || forest[r][c] == 0)
            continue;
          if (r == er && c == ec)
            return step;
          visited[r][c] = 1;
          myq.push({r, c});
        }
      }
    }
    return -1;
  }
};
