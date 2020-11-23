#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    vector<int> a1(n, 0), a2(m, 0);
    unordered_map<int, int> m1, m2;

    for (auto &i : a1)
    {
      cin >> i;
      m1[i]++;
    }
    for (auto &i : a2)
    {
      cin >> i;
      m2[i]++;
    }

    bool flag = true;
    for (auto it = m2.begin(); it != m2.end(); ++it)
    {
      int e = it->first, f = it->second;
      if (m1[e] < f)
      {
        flag = false;
        break;
      }
    }

    if (flag)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}