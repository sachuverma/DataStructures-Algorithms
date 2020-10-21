#include <bits/stdc++.h>
using namespace std;

void rearrange(vector<int> &arr)
{
  int p = 0, i = 0;
  while (i < arr.size())
  {
    while (p < arr.size() && arr[p] < 0)
      p++;
    i = p;
    while (i < arr.size() && arr[i] >= 0)
      i++;
    if (p >= arr.size() || i >= arr.size())
      break;
    int temp = arr[i];
    for (int j = i - 1; j >= p; --j)
      arr[j + 1] = arr[j];
    arr[p] = temp;
  }
}

int main()
{
  int n;
  cin >> n;

  vector<int> arr(n);
  for (auto &i : arr)
    cin >> i;

  rearrange(arr);

  for (auto &i : arr)
    cout << i << " ";
  cout << endl;

  return 0;
}
