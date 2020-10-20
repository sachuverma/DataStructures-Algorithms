// O(nlogn)
int find_median(vector<int> v)
{
  sort(v.begin(), v.end());
  int n = v.size();
  int ans = 0;

  if (n % 2 == 0)
    ans = (v[(n / 2) - 1] + v[(n / 2)]) / 2;
  else
    ans = v[((n + 1) / 2) - 1];

  return ans;
}
