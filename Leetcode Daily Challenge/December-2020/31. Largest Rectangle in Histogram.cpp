/*
Largest Rectangle in Histogram
==============================

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:
Input: [2,1,5,6,2,3]
Output: 10
*/

class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int n = heights.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return heights[0];
    int ans = 0;

    vector<int> lb(n, 0), rb(n, 0);
    stack<int> ls, rs;

    for (int i = 0; i < n; ++i)
    {
      while (ls.size() && heights[ls.top()] >= heights[i])
        ls.pop();
      if (ls.size())
        lb[i] = ls.top();
      else
        lb[i] = -1;
      ls.push(i);
    }

    for (int i = n - 1; i >= 0; --i)
    {
      while (rs.size() && heights[rs.top()] >= heights[i])
        rs.pop();
      if (rs.size())
        rb[i] = rs.top();
      else
        rb[i] = n;
      rs.push(i);
    }

    for (int i = 0; i < n; ++i)
    {
      int width = rb[i] - lb[i] - 1;
      int area = heights[i] * width;
      ans = max(ans, area);
    }

    return ans;
  }
};
