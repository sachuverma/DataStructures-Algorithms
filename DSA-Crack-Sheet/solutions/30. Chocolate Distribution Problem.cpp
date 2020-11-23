// O(nlogn)
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
      cin >> i;
    cin >> k;

    sort(arr.begin(), arr.end());
    int ans = INT_MAX;
    for (int i = 0; i < n - k + 1; ++i)
      ans = min(ans, arr[i + k - 1] - arr[i]);

    cout << ans << endl;
  }
  return 0;
}
