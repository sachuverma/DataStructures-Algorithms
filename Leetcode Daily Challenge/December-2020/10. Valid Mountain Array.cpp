/*
Valid Mountain Array
====================

Given an array of integers arr, return true if and only if it is a valid mountain array.
Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < A[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Example 1:
Input: arr = [2,1]
Output: false

Example 2:
Input: arr = [3,5,5]
Output: false

Example 3:
Input: arr = [0,3,2,1]
Output: true

Constraints:
1 <= arr.length <= 104
0 <= arr[i] <= 104

Hint #1  
It's very easy to keep track of a monotonically increasing or decreasing ordering of elements. You just need to be able to determine the start of the valley in the mountain and from that point onwards, it should be a valley i.e. no mini-hills after that. Use this information in regards to the values in the array and you will be able to come up with a straightforward solution.
*/

class Solution
{
public:
  bool validMountainArray(vector<int> &A)
  {
    if (A.size() <= 2)
      return false;
    if (A[0] >= A[1])
      return false;
    if (A[A.size() - 2] <= A[A.size() - 1])
      return false;

    int inc = 1, change = 0;
    for (int i = 0; i < A.size() - 1; ++i)
    {
      if (inc == 1)
      {
        if (A[i] < A[i + 1])
          ;
        else if (A[i] == A[i + 1])
          return false;
        else
        {
          inc = 0;
          change = 1;
        }
      }
      else
      {
        if (A[i] > A[i + 1] && change)
          ;
        else
          return false;
      }
    }

    if (!change)
      return false;
    return true;
  }
};
