// sorting O(nlogn)

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
      cin >> i;
    int k;
    cin >> k;

    sort(arr.begin(), arr.end());
    cout << arr[k - 1] << endl;
  }
  return 0;
}

/* ======================================== */
// building min heap O(n + klogn)

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
      cin >> arr[i];

    make_heap(arr.begin(), arr.end());
    int k;
    cin >> k;

    for (int i = 0; i < n - k; ++i)
    {
      pop_heap(arr.begin(), arr.end());
      arr.pop_back();
    }
    cout << arr.front() << endl;
  }
  return 0;
}
