/*
Rat in a Maze Problem
=====================

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:
Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.

Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((N2)4).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1
*/

char Dirs[4] = {'D', 'L', 'R', 'U'};
int dirs[4][4] = {
    {1, 0}, {0, -1}, {0, 1}, {-1, 0}};

bool valid(int i, int j, vector<vector<int>> &mat)
{
  return i >= 0 && j >= 0 && i < mat.size() && j < mat[0].size() && mat[i][j];
}

void dfs(int r, int c, vector<vector<int>> &mat, vector<string> &ans, string atn)
{
  if (!valid(r, c, mat))
    return;
  int n = mat.size(), m = mat[0].size();
  if (r == n - 1 && c == m - 1)
  {
    ans.push_back(atn);
    return;
  }

  mat[r][c] = 0;
  for (int i = 0; i < 4; ++i)
    dfs(r + dirs[i][0], c + dirs[i][1], mat, ans, atn + Dirs[i]);

  mat[r][c] = 1;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
  vector<string> ans;
  dfs(0, 0, m, ans, "");
  return ans.size() == 0 ? vector<string>() : ans;
}
