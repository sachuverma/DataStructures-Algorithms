/*
Largest Rectangle in Histogram
==============================

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4

Constraints:
1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int n = heights.size();
    vector<int> left(n, 0), right(n, 0);
    int ans = 0;

    left[0] = -1;
    right[n - 1] = n;

    for (int i = 1; i < n; ++i)
    {
      int pos = i - 1;
      while (pos >= 0 && heights[pos] >= heights[i])
        pos = left[pos];
      left[i] = pos;
    }

    for (int i = n - 2; i >= 0; --i)
    {
      int pos = i + 1;
      while (pos < n && heights[pos] >= heights[i])
        pos = right[pos];
      right[i] = pos;
    }

    for (int i = 0; i < heights.size(); ++i)
      ans = max(ans, heights[i] * (right[i] - left[i] - 1));

    return ans;
  }
};
