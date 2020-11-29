
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n, 0), b(m, 0);
    for (auto &i : a)
      cin >> i;
    for (auto &i : b)
      cin >> i;

    int i = 0, j = 0;
    int ans = -1;

    while (i < n && j < m && k)
    {
      if (a[i] <= b[j])
      {
        ans = 0;
        i++;
      }
      else
      {
        ans = 1;
        j++;
      }
      k--;
    }
    while (i < n && k)
    {
      ans = 0;
      i++;
      k--;
    }
    while (j < m && k)
    {
      ans = 1;
      j++;
      k--;
    }

    if (ans == 0)
      cout << a[--i] << endl;
    else
      cout << b[--j] << endl;
  }
  return 0;
}
