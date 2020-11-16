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
    if (a[0] == b[0])
      return a[1] < b[1];
    return a[0] < b[0];
  }

public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end(), comp);
    stack<vector<int>> s;

    for (auto interval : intervals)
    {
      if (!s.size())
        s.push(interval);
      else
      {
        auto lastInterval = s.top();
        s.pop();
        if (interval[0] <= lastInterval[1] && interval[0] >= lastInterval[0])
        {
          lastInterval[1] = max(lastInterval[1], interval[1]);
          s.push(lastInterval);
        }
        else
        {
          s.push(lastInterval);
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
