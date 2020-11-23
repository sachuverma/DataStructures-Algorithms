// O(n2)
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

    int ans = INT_MIN;

    for (int i = 0; i < n; ++i)
    {
      int curr_sum = 0;
      for (int j = i; j < n; ++j)
      {
        curr_sum += arr[j];
        ans = max(ans, curr_sum);
      }
    }

    cout << ans << endl;
  }
  return 0;
}

/* ====================================== */
// O(n)
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

    vector<int> dp(n);
    dp[n - 1] = arr[n - 1];
    int ans = dp[n - 1];

    for (int i = n - 2; i >= 0; --i)
    {
      dp[i] = max(arr[i], arr[i] + dp[i + 1]);
      ans = max(ans, dp[i]);
    }

    cout << ans << endl;
  }
  return 0;
}

/* ====================================== */
// O(n)
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

    int msf = INT_MIN; // max so far
    int meh = 0;       // max ending here

    for (int i = 0; i < n; ++i)
    {
      meh += arr[i];
      msf = max(msf, meh);
      if (meh < 0)
        meh = 0;
    }

    cout << msf << endl;
  }
  return 0;
}
