#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (auto &i : arr)
      cin >> i;

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
      int sum = 0;
      for (int j = i; j < n; ++j)
      {
        sum += arr[j];
        if (sum > x)
          ans = min(ans, j - i + 1);
      }
    }
    cout << ans << endl;
  }
  return 0;
}