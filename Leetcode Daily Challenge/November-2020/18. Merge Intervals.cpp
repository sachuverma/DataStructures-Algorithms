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
  bool static compare(vector<int> &a, vector<int> &b)
  {
    return a[0] < b[0];
  }

public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end(), compare);
    stack<vector<int>> s;

    for (auto interval : intervals)
    {
      if (!s.size())
        s.push(interval);
      else
      {
        auto prev = s.top();
        s.pop();

        if (prev[0] <= interval[0] && prev[1] >= interval[0])
        {
          s.push({min(prev[0], interval[0]), max(prev[1], interval[1])});
        }
        else
        {
          s.push(prev);
          s.push(interval);
        }
      }
    }

    vector<vector<int>> ans;
    while (s.size())
    {
      ans.push_back(s.top());
      s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
