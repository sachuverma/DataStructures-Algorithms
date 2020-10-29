
#include <bits/stdc++.h>
using namespace std;

void print(string s, string ans = "")
{
  if (s == "")
  {
    cout << ans << endl;
    return;
  }
  string next = s.substr(1);
  print(next, ans);
  print(next, ans + s[0]);
}

int main()
{
  string s;
  cin >> s;
  print(s);

  return 0;
}
