// O(nlogn)
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
    vector<int> arr(n, 0);
    for (auto &i : arr)
      cin >> i;

    sort(arr.begin(), arr.end());
    int ans = INT_MIN;
    int count = 0;
    for (int i = 0; i < n - 1; ++i)
    {
      if (arr[i] + 1 == arr[i + 1])
        count++;
      else if (arr[i] == arr[i + 1])
        ;
      else
        count = 0;
      ans = max(ans, count);
    }

    if (ans == INT_MIN)
      ans = 0;
    cout << ++ans << endl;
  }
  return 0;
}

/* ================================================ */
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
    vector<int> arr(n, 0);
    for (auto &i : arr)
      cin >> i;

    unordered_set<int> s;
    for (auto i : arr)
      s.insert(i);

    int ans = 0;
    for (auto i : arr)
    {
      if (s.find(i - 1) == s.end())
      {
        int j = i;
        while (s.find(j) != s.end())
          j++;
        ans = max(ans, j - i);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
