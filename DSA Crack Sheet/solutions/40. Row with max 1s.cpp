// O(n2)
int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
  int ans = -1, max_count = 0;
  for (int i = 0; i < n; ++i)
  {
    int count = 0;
    for (int j = 0; j < m; ++j)
      count += arr[i][j];
    if (count > max_count)
    {
      max_count = count;
      ans = i;
    }
  }
  return ans;
}

/* ================================================= */
// O(nlogn)
int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
  int ans = -1, max_count = 0;
  for (int i = 0; i < n; ++i)
  {
    auto upperBound = upper_bound(arr[i].begin(), arr[i].end(), 0);
    int count = m - (upperBound - arr[i].begin());
    if (count > max_count)
    {
      max_count = count;
      ans = i;
    }
  }
  return ans;
}

/* ================================================= */
// O(n)
