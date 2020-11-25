#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> powers(n, 0);
  for (auto &i : powers)
    cin >> i;

  int q;
  cin >> q;
  while (q--)
  {
    int bishu;
    cin >> bishu;
    int total_pow = 0, count = 0;
    for (auto &i : powers)
    {
      if (i <= bishu)
      {
        total_pow += i;
        count++;
      }
    }
    cout << count << " " << total_pow << endl;
  }

  return 0;
}
