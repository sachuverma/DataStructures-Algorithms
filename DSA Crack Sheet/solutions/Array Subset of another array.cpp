/*
Array Subset of another array
=============================

Given two arrays: arr1[0..m-1] of size m and arr2[0..n-1] of size n. Task is to check whether arr2[] is a subset of arr1[] or not. Both the arrays can be both unsorted or sorted. It may be assumed that elements in both array are distinct.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an two integers m and n denoting the size of arr1 and arr2 respectively. The following two lines contains the space separated elements of arr1 and arr2 respectively.

Output:
Print "Yes"(without quotes) if arr2 is subset of arr1.
Print "No"(without quotes) if arr2 is not subset of arr1.

Constraints:
1 <= T <= 100
1 <= m,n <= 105
1 <= arr1[i], arr2[j] <= 105

Example:
Input:
3
6 4
11 1 13 21 3 7
11 3 7 1
6 3
1 2 3 4 5 6
1 2 4
5 3
10 5 2 23 19
19 5 3

Output:
Yes
Yes
No

Explanation:
Testcase 1: (11, 3, 7, 1) is a subset of first array.
*/

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &a, vector<int> &b)
{
  unordered_map<int, int> f;
  for (auto &i : a)
    f[i]++;
  for (auto &i : b)
  {
    if (f[i] <= 0)
      return false;
    f[i]--;
  }
  return true;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0), b(m, 0);
    for (auto &i : a)
      cin >> i;
    for (auto &i : b)
      cin >> i;

    if (check(a, b))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
