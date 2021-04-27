/*
Trapping Rain Water
==================

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:
n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105
*/

class Solution
{
public:
  int trap(vector<int> &h)
  {
    int n = h.size();
    if (n <= 1)
      return 0;
    int ans = 0;
    int i = 0, j = n - 1;
    int left = h[0], right = h[n - 1];

    while (i <= j)
    {
      left = max(left, h[i]);
      right = max(right, h[j]);

      if (min(left, right) >= h[i])
        ans += min(left, right) - h[i];

      if (min(left, right) >= h[j])
        ans += min(left, right) - h[j];

      if (h[i] < h[j])
        i++;
      else
        j--;
    }

    return ans;
  }
};
