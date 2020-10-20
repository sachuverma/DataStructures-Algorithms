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
    int k;
    cin >> k;

    int count = 0;
    for (int i = 0; i < n; ++i)
      if (arr[i] <= k)
        ++count;

    int bad = 0;
    for (int i = 0; i < count; ++i)
      if (arr[i] > k)
        ++bad;

    int ans = bad;
    for (int i = 0, j = count; j < n; ++i, ++j)
    {
      if (arr[i] > k)
        --bad;
      if (arr[j] > k)
        ++bad;
      ans = min(ans, bad);
    }

    cout << ans << endl;
  }
  return 0;
}