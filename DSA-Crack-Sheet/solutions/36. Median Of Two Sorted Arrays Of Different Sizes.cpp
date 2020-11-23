#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> ar1(n), ar2(m);
  for (auto &i : ar1)
    cin >> i;
  for (auto &i : ar2)
    cin >> i;

  int i = 0;
  int j = 0;
  int count;
  int m1 = -1, m2 = -1;

  if ((m + n) % 2 == 1)
  {
    for (count = 0; count <= (n + m) / 2; count++)
    {
      if (i != n && j != m)
        m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];

      else if (i < n)
        m1 = ar1[i++];

      else
        m1 = ar2[j++];
    }
    cout << m1;
  }

  else
  {
    for (count = 0; count <= (n + m) / 2; count++)
    {
      m2 = m1;
      if (i != n && j != m)
        m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];

      else if (i < n)
        m1 = ar1[i++];

      else
        m1 = ar2[j++];
    }

    cout << (m1 + m2) / 2;
  }
  return 0;
}
