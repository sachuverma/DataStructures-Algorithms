
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
      cin >> i;

    int incl = arr[0], excl = 0, excl_new;
    for (int i = 1; i < n; i++)
    {
      excl_new = max(incl, excl);
      incl = excl + arr[i];
      excl = excl_new;
    }

    cout << max(incl, excl) << endl;
  }
  return 0;
}
