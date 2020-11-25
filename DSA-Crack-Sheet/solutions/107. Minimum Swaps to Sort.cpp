
int minSwaps(int arr[], int N)
{
  vector<pair<int, int>> P;
  for (int i = 0; i < N; ++i)
    P.push_back({arr[i], i});
  sort(P.begin(), P.end());
  vector<bool> visited(N, false);
  int ans = 0;

  for (int i = 0; i < N; ++i)
  {
    if (visited[i] || P[i].second == i)
      continue;

    int j = i;
    int cycles = 0;
    while (!visited[j])
    {
      visited[j] = true;
      j = P[j].second;
      cycles++;
    }

    if (cycles > 0)
      ans += cycles - 1;
  }
  return ans;
}
