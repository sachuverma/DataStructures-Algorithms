
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int zero = 0, one = 0, count = 0;

  for (auto ch : s)
  {
    if (ch == '0')
      zero++;
    else
      one++;

    if (zero == one)
      count++;
  }

  if (zero != one)
    cout << -1;
  else
    cout << count;

  return 0;
}
