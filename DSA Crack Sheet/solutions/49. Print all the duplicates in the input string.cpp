
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  getline(cin, s);
  vector<int> arr(26, 0);
  for (auto ch : s)
    arr[ch - 'a']++;
  for (auto i = 0; i < 26; ++i)
    if (arr[i] > 1)
      cout << (char)('a' + i) << " ";
  return 0;
}
