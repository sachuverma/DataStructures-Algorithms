/*
Arithmetic Slices
=================

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of the array A is called arithmetic if the sequence:
A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.

Example:
A = [1, 2, 3, 4]
return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
*/

class Solution
{
public:
  int nThSum(int n)
  {
    return n * (n + 1) / 2;
  }

  int numberOfArithmeticSlices(vector<int> &A)
  {
    if (A.size() <= 2)
      return 0;

    int ans = 0, count = 0;
    int a = 0, b = 1, diff = A[1] - A[0];

    while (b < A.size())
    {
      if (A[b] - A[a] == diff)
      {
        count++;
        a++;
        b++;
      }
      else
      {
        if (count > 1)
        {
          int nums = count - 1;
          ans += nThSum(nums);
        }
        count = 0;
        diff = A[b] - A[a];
      }
    }

    if (count > 1)
    {
      int nums = count - 1;
      ans += nThSum(nums);
    }

    return ans;
  }
};
