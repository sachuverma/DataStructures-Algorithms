/*
Find K Closest Elements
=======================

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

Constraints:
1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104
*/

class Solution
{
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x)
  {
    sort(arr.begin(), arr.end(), [x](int &a, int &b)
         {
           if (abs(a - x) == abs(b - x))
             return a < b;
           return abs(a - x) < abs(b - x);
         });

    vector<int> ans = vector<int>(arr.begin(), arr.begin() + k);
    sort(ans.begin(), ans.end());
    return ans;
  }
};