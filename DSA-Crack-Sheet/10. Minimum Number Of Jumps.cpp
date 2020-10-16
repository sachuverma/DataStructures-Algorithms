#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
      cin >> i;

    vector<int> dp(n, 0);
    for (int i = n - 2; i >= 0; --i)
    {
      int max_jumps_can_make = arr[i];
      int Min = INT_MAX;
      for (int j = 1; j <= max_jumps_can_make; ++j)
      {
        if (i + j < n)
          Min = min(Min, dp[i + j]);
      }
      if (Min == INT_MAX)
        dp[i] = Min;
      else
        dp[i] = Min + 1;
    }
    if (dp[0] == INT_MAX)
      cout << -1 << endl;
    else
      cout << dp[0] << endl;
  }
  return 0;
}