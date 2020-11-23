// O(n2)
long long maxProduct(int *arr, int n)
{
  long long ans = INT_MIN;
  for (int i = 0; i < n; ++i)
  {
    long long prod = 1;
    for (int j = i; j < n; ++j)
    {
      prod *= arr[j];
      ans = max(ans, prod);
    }
  }
  return ans;
}

// =====================================
// O(n)
long long maxProduct(int *arr, int n)
{
  long long max_here = arr[0], min_here = arr[0], ans = arr[0];
  for (int i = 1; i < n; ++i)
  {
    if (arr[i] < 0)
      swap(max_here, min_here);

    max_here = max((long long)arr[i], max_here * arr[i]);
    min_here = min((long long)arr[i], min_here * arr[i]);

    ans = max(ans, max_here);
  }
  return ans;
}
