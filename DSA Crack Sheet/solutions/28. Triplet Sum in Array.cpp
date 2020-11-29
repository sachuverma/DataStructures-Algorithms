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
    vector<int> arr(n, 0);
    for (auto &i : arr)
      cin >> i;

    bool found = false;

    for (int i = 0; i < n - 2; i++)
    {
      unordered_set<int> s;
      int curr_sum = x - arr[i];
      for (int j = i + 1; j < n; j++)
      {
        int target = curr_sum - arr[j];
        if (s.find(target) != s.end())
        {
          found = true;
          break;
        }
        s.insert(arr[j]);
      }
    }

    if (found)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
