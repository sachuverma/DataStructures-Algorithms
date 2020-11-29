// O(n2)
int getPairsCount(int arr[], int n, int sum)
{
  int count = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (arr[i] + arr[j] == sum)
        count++;

  return count;
}

/* ========================================= */
// O(n)
int getPairsCount(int arr[], int n, int k)
{
  int count = 0;
  unordered_map<int, int> Map;
  for (int i = 0; i < n; ++i)
  {
    int target = k - arr[i];
    if (Map.find(target) != Map.end())
      count += Map[target];
    Map[arr[i]]++;
  }
  return count;
}

