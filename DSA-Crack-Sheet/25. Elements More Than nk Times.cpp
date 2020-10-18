#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> arr = {1, 2, 3, 4, 1, 1, 1, 2, 2, 3, 3, 5, 5, 6, 7, 7, 5, 4, 8, 9};
  int n = arr.size(), k = 9;

  unordered_map<int, int> m;
  for (auto i : arr)
    m[i]++;

  for (auto it = m.begin(); it != m.end(); ++it)
    if (it->second > n / k)
      cout << it->first << " ";

  return 0;
}