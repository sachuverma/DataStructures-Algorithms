/*
First and last occurrences of X
===============================

Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

Note: If the number x is not found in the array just print '-1'.

Input:
The first line consists of an integer T i.e number of test cases. The first line of each test case contains two integers n and x. The second line contains n spaced integers.

Output:
Print index of the first and last occurrences of the number x with a space in between.

Constraints: 
1<=T<=100
1<=n,a[i]<=1000

Example:
Input:
2
9 5
1 3 5 5 5 5 67 123 125
9 7
1 3 5 5 5 5 7 123 125
Output:
2 5
6 6
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (auto &i : arr)
      cin >> i;

    int first = -1, last = -1;
    for (int i = 0; i < n; ++i)
    {
      if (arr[i] == x)
      {
        first = i;
        break;
      }
    }

    if (first == -1)
    {
      cout << -1 << endl;
      continue;
    }

    for (int i = n - 1; i >= 0; --i)
    {
      if (arr[i] == x)
      {
        last = i;
        break;
      }
    }

    cout << first << " " << last << endl;
  }
  return 0;
}
