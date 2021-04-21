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
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end());
    stack<vector<int>> st;
    st.push(intervals[0]);
    vector<vector<int>> ans;

    for (int i = 1; i < intervals.size(); ++i)
    {
      auto curr = intervals[i];
      auto prev = st.top();
      st.pop();
      if (curr[0] >= prev[0] && curr[0] <= prev[1])
      {
        auto merged = prev;
        merged[1] = max(prev[1], curr[1]);
        st.push(merged);
      }
      else
      {
        st.push(prev);
        st.push(curr);
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
