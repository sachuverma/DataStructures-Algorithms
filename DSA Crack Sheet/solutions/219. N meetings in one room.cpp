
#define piii pair<int, pair<int, int>>
bool comp(piii &a, piii &b)
{
  if (a.second.second == b.second.second)
    return a.first < b.first;
  return a.second.second < b.second.second;
}

void maxMeetings(int start[], int end[], int n)
{
  vector<piii> meets(n, {0, {0, 0}});
  for (int i = 0; i < n; ++i)
    meets[i].first = i + 1;
  for (int i = 0; i < n; ++i)
    meets[i].second.first = start[i];
  for (int i = 0; i < n; ++i)
    meets[i].second.second = end[i];

  sort(meets.begin(), meets.end(), comp);
  vector<int> ans;

  ans.push_back(meets[0].first);
  int time_limit = meets[0].second.second;

  for (int i = 1; i < n; i++)
  {
    if (meets[i].second.first >= time_limit)
    {
      ans.push_back(meets[i].first);
      time_limit = meets[i].second.second;
    }
  }

  for (auto &i : ans)
    cout << i << " ";
}
