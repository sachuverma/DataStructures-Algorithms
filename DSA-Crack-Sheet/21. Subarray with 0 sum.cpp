// O(n2)
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
    for (auto &i : arr)
      cin >> i;

    bool found = false;
    for (int i = 0; i < n; ++i)
    {
      int sum = 0;
      for (int j = i; j < n; ++j)
      {
        sum += arr[j];
        if (sum == 0)
        {
          found = true;
          break;
        }
      }
      if (found)
        break;
    }

    if (found)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}

/* ====================================== */
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
    for (auto &i : arr)
      cin >> i;

    bool found = false;
    set<int> s;

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
      s.insert(sum);
      sum += arr[i];
      if (s.find(sum) != s.end())
      {
        found = true;
        break;
      }
    }

    if (found)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}

/* ====================================== */
// nums of subarray with sum k
// O(n)

class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    map<int, int> m;
    int sum = 0, count = 0;
    for (auto i : nums)
    {
      m[sum]++;
      sum += i;
      if (m.find(sum - k) != m.end())
        count += m[sum - k];
    }

    return count;
  }
};
