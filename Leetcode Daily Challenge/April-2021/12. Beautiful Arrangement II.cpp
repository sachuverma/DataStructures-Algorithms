/*
Beautiful Arrangement II
========================

Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement:
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

If there are multiple answers, print any of them.

Example 1:
Input: n = 3, k = 1
Output: [1, 2, 3]
Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.

Example 2:
Input: n = 3, k = 2
Output: [1, 3, 2]
Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.

Note:
The n and k are in the range 1 <= k < n <= 104.
*/

class Solution
{
public:
  vector<int> constructArray(int n, int k)
  {
    vector<int> arr(n, 0);
    for (auto i = 1; i <= n; ++i)
      arr[i - 1] = i;

    if (k == 1)
      return arr;
    vector<int> prev = arr;
    int j = 1;

    for (int i = 1; i < k; ++i)
    {
      if (i % 2 != 0)
      {
        prev = arr;
        swap(arr[n - 2], arr[n - 1]);
      }
      else
      {
        arr = prev;
        rotate(arr.begin() + j, arr.begin() + n - 1, arr.end());
        j += 2;
      }
    }
    return arr;
  }
};