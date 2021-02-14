/*
Rearrange array in alternating positive & negative items with O(1) extra space
==============================================================================

Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa maintaining the order of appearance. 
Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.

Examples : 

Input:  arr[] = {1, 2, 3, -4, -1, 4}
Output: arr[] = {-4, 1, -1, 2, 3, 4}

Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0} 
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> arr = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8, -1, -2, -3, -4, -5, -6, -4};
  int i = 0, n = arr.size();

  while (i < n)
  {
    int next_sign = 0;
    while (i < n && ((i % 2 == 0 && arr[i] < 0) || (i % 2 && arr[i] >= 0)))
      i++;
    if (i >= n)
      break;

    int j = i + 1;

    if (arr[i] < 0)
    {
      // find next +ve
      while (j < n && arr[j] < 0)
        j++;
      if (j >= n)
        break;
    }
    else
    {
      // find next -ve
      while (j < n && arr[j] >= 0)
        j++;
      if (j >= n)
        break;
    }

    // rotate right one i to j
    int temp = arr[j];
    for (int k = j; k >= i + 1; --k)
      arr[k] = arr[k - 1];
    arr[i] = temp;
  }

  for (auto &i : arr)
    cout << i << " ";
  return 0;
}
