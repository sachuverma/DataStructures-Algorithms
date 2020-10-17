bool compare(vector<int> &a, vector<int> &b)
{
  if (a[0] == b[0])
    return a[1] < b[1];
  return a[0] < b[0];
}

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &arr)
  {
    sort(arr.begin(), arr.end(), compare);
    stack<vector<int>> s;

    for (auto i : arr)
    {
      if (s.empty())
        s.push(i);
      else
      {
        auto t = s.top();
        if (i[0] <= t[1] && i[0] >= t[0])
        {
          if (i[1] > t[1])
          {
            s.pop();
            t[1] = i[1];
            s.push(t);
          }
        }
        else
          s.push(i);
      }
    }

    vector<vector<int>> ans;
    while (s.size())
    {
      ans.push_back(s.top());
      s.pop();
    }

    return ans;
  }
};