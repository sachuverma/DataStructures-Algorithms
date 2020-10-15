// O(nlogn)

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
    vector<int> arr(n, 0);

    for (int i = 0; i < n; ++i)
      cin >> arr[i];

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
    cout << endl;
  }
  return 0;
}

/* =============================== */
// O(n)

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
    vector<int> arr(n, 0);
    int num[3] = {0};

    for (int i = 0; i < n; ++i)
    {
      cin >> arr[i];
      num[arr[i]]++;
    }

    for (int i = 0; i < n; ++i)
    {
      if (num[0])
      {
        arr[i] = 0;
        num[0]--;
      }
      else if (num[1])
      {
        arr[i] = 1;
        num[1]--;
      }
      else if (num[2])
      {
        arr[i] = 2;
        num[2]--;
      }
    }

    for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
    cout << endl;
  }
  return 0;
}