
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    int f = 0, b = s.size() - 1;

    while (f < b)
    {
      char ch = s[f];
      s[f] = s[b];
      s[b] = ch;
      f++;
      b--;
    }

    cout << s << endl;
  }
  return 0;
}
