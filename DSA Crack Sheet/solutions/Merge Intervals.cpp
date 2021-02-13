/*
Merge Intervals
===============

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Constraints:
1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

class Solution
{
  bool static comp(vector<int> &a, vector<int> &b)
  {
    return a[0] < b[0];
  }

public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    if (!intervals.size())
      return {};

    sort(intervals.begin(), intervals.end(), comp);
    vector<vector<int>> ans;
    stack<vector<int>> st;

    for (auto &i : intervals)
    {
      if (!st.size())
        st.push(i);
      else
      {
        auto curr = st.top();
        st.pop();
        if (i[0] >= curr[0] && i[0] <= curr[1])
        {
          curr[1] = max(curr[1], i[1]);
          st.push(curr);
        }
        else
        {
          st.push(curr);
          st.push(i);
        }
      }
    }

    while (st.size())
    {
      ans.push_back(st.top());
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
