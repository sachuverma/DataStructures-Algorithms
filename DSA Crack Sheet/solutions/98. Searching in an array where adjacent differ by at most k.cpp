#include <bits/stdc++.h>
using namespace std;

int found(vector<int> &arr, int &target, int &k)
{
  int i = 0;
  while (i < arr.size())
  {
    if (arr[i] == target)
      return i;
    i = i + max(1, abs(arr[i] - target) / k);
  }

  return -1;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n, 0);
  for (auto &i : arr)
    cin >> i;
  int target;
  cin >> target;

  if (found(arr, target, k) != -1)
    cout << "found";
  else
    cout << "not found";
  cout << endl;

  return 0;
}
