ll findSubarray(vector<ll> arr, int n)
{
  unordered_map<int, vector<int>> sums;
  ll sum = 0;
  ll ans = 0;
  for (int i = 0; i < n; ++i)
  {
    sum += arr[i];
    if (sum == 0)
      ans++;
    if (sums.find(sum) != sums.end())
      ans += sums[sum].size();
    sums[sum].push_back(i);
  }
  return ans;
}
