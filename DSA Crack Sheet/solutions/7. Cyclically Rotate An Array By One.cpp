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

    int temp = arr[n - 1];
    for (int i = n - 2; i >= 0; --i)
      arr[i + 1] = arr[i];
    arr[0] = temp;

    for (auto i : arr)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}