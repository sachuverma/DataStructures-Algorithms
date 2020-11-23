
#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<string> keycodes = {
      "2", "22", "222",
      "3", "33", "333",
      "4", "44", "444",
      "5", "55", "555",
      "6", "66", "666",
      "7", "77", "777", "7777",
      "8", "88", "888",
      "9", "99", "999", "9999"};

  string str;
  getline(cin, str);
  for (auto ch : str)
  {
    if (ch == ' ')
      cout << 0;
    else
      cout << keycodes[ch - 'A'];
  }

  return 0;
}
