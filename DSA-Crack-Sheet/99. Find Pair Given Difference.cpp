
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int l, n;
    cin >> l >> n;
    vector<int> arr(l, 0);
    for (auto &i : arr)
      cin >> i;

    unordered_map<int, int> m;
    int found = 0;

    for (auto &i : arr)
    {
      int target1 = abs(n - i), target2 = n + i;
      if (m.find(target1) != m.end() || m.find(target2) != m.end())
      {
        found = 1;
        break;
      }
      else
        m[i]++;
    }

    if (found == 1)
      cout << 1 << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
