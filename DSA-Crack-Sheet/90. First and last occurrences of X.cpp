
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

    int ans = -1;
    for (int i = 0, j = n - 1; i <= j;)
    {
      int mid = (i + j) / 2;
      if (arr[mid] == x)
      {
        j = mid - 1;
        ans = mid;
      }
      else if (arr[mid] < x)
        i = mid + 1;
      else
        j = mid - 1;
    }
    cout << ans << " ";

    if (ans == -1)
    {
      cout << endl;
      continue;
    }

    ans = -1;
    for (int i = 0, j = n - 1; i <= j;)
    {
      int mid = (i + j) / 2;
      if (arr[mid] == x)
      {
        i = mid + 1;
        ans = mid;
      }
      else if (arr[mid] < x)
        i = mid + 1;
      else
        j = mid - 1;
    }
    cout << ans << endl;
  }
  return 0;
}
