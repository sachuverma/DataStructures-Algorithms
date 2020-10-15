// O(nlogn)
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &i : arr)
    cin >> i;

  sort(arr.begin(), arr.end());

  for (auto &i : arr)
    cout << i << " ";
  cout << endl;

  return 0;
}

/* =========================== */
// O(n)
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &i : arr)
    cin >> i;

  int i = 0, j = n - 1;
  while (i < j)
  {
    while (arr[i] < 0)
      i++;
    while (arr[j] >= 0)
      j--;

    if (i >= j)
      break;
    swap(arr[i], arr[j]);
    i++;
    j--;
  }

  for (auto &i : arr)
    cout << i << " ";
  cout << endl;

  return 0;
}
