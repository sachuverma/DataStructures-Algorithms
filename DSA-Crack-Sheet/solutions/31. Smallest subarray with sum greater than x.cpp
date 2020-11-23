// O(n2)
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

/* =================================== */
// O(n)

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

    int curr_sum = 0, ans = n + 1;
    int start = 0, end = 0;
    while (end < n)
    {
      while (curr_sum <= x && end < n)
        curr_sum += arr[end++];
      while (curr_sum > x && start < n)
      {
        if (end - start < ans)
          ans = end - start;
        curr_sum -= arr[start++];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
