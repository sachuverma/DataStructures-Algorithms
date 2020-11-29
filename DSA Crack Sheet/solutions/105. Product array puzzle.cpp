
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
  vector<long long int> left(n), right(n), ans(n);
  long long prod = 1;
  for (int i = 0; i < n; ++i)
  {
    left[i] = prod;
    prod *= nums[i];
  }
  prod = 1;
  for (int i = n - 1; i >= 0; --i)
  {
    right[i] = prod;
    prod *= nums[i];
  }
  for (int i = 0; i < n; ++i)
    ans[i] = left[i] * right[i];
  return ans;
}
