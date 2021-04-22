/*
Brick Wall
==========

There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same height but different width. You want to draw a vertical line from the top to the bottom and cross the least bricks.

The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row from left to right.

If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks.

You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

Example:
Input: [[1,2,2,1],
        [3,1,2],
        [1,3,2],
        [2,4],
        [3,1,2],
        [1,3,1,1]]
Output: 2

Note:
The width sum of bricks in different rows are the same and won't exceed INT_MAX.
The number of bricks in each row is in range [1,10,000]. The height of wall is in range [1,10,000]. Total number of bricks of the wall won't exceed 20,000.
*/

class Solution
{
public:
  int leastBricks(vector<vector<int>> &wall)
  {
    if (wall.size() == 1)
    {
      if (wall[0].size() == 1)
        return 1;
      return 0;
    }

    if (wall[0].size() == 1 && wall[0][0] == 1)
      return wall.size();
    vector<vector<int>> dp;

    for (auto &row : wall)
    {
      vector<int> arr = {row[0]};
      for (int i = 1; i < row.size(); ++i)
      {
        arr.push_back({arr[i - 1] + row[i]});
      }
      dp.push_back(arr);
    }

    int ans = INT_MIN;
    unordered_map<int, int> freq;

    for (auto &row : dp)
    {
      for (auto &i : row)
      {
        if (i != dp[0][dp[0].size() - 1])
          freq[i]++;
        ans = max(ans, freq[i]);
      }
    }
    return dp.size() - ans;
  }
};
