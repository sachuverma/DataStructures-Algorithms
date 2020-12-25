/*
Diagonal Traverse
=================

Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]

Note:
The total number of elements of the given matrix will not exceed 10,000.
*/

class Solution
{
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
  {
    if (!matrix.size() || !matrix[0].size())
      return {};
    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
    visited[0][0] = true;
    queue<vector<int>> pending;
    pending.push({0, 0});
    vector<vector<int>> dirs = {
        {0, 1}, {1, 0}};

    vector<int> ans;
    int turn = 1;

    while (pending.size())
    {
      vector<int> sub;
      int size = pending.size();
      for (int i = 0; i < size; ++i)
      {
        auto curr = pending.front();
        pending.pop();
        sub.push_back(matrix[curr[0]][curr[1]]);

        for (auto &dir : dirs)
        {
          int nextI = curr[0] + dir[0], nextJ = curr[1] + dir[1];
          if (nextI >= matrix.size() || nextJ >= matrix[0].size() || visited[nextI][nextJ])
            continue;
          visited[nextI][nextJ] = true;
          pending.push({nextI, nextJ});
        }
      }

      if (turn)
      {
        turn = 0;
        for (int i = sub.size() - 1; i >= 0; --i)
          ans.push_back(sub[i]);
      }
      else
      {
        turn = 1;
        for (int i = 0; i < sub.size(); ++i)
          ans.push_back(sub[i]);
      }
    }
    return ans;
  }
};
