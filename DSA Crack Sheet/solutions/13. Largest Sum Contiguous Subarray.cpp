
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

    int msf = INT_MIN; // max so far
    int meh = 0;       // max ending here

    for (int i = 0; i < n; ++i)
    {
      meh += arr[i];
      msf = max(msf, meh);
      if (meh < 0)
        meh = 0;
    }

    cout << msf << endl;
  }
  return 0;
}
