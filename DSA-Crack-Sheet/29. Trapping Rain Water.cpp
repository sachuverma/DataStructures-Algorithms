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

    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
      int left = arr[i];
      int right = arr[i];

      for (int j = 0; j < i; j++)
        left = max(left, arr[j]);
      for (int j = i + 1; j < n; j++)
        right = max(right, arr[j]);
      res = res + (min(left, right) - arr[i]);
    }

    cout << res << endl;
  }
  return 0;
}

/* =================================================== */
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

    vector<int> left_max(n), right_max(n);

    left_max[0] = arr[0];
    for (int i = 1; i < n; i++)
      left_max[i] = max(left_max[i - 1], arr[i]);

    right_max[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
      right_max[i] = max(right_max[i + 1], arr[i]);

    int res = 0;
    for (int i = 1; i < n - 1; i++)
      res = res + (min(left_max[i], right_max[i]) - arr[i]);

    cout << res << endl;
  }
  return 0;
}
