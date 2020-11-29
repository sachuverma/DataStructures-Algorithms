/*
Sqrt(x)
======

Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Example 1:
Input: x = 4
Output: 2

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

Constraints:
0 <= x <= 231 - 1

Hint #1  
Try exploring all integers. (Credits: @annujoshi)

Hint #2  
Use the sorted property of integers to reduced the search space. (Credits: @annujoshi)
*/

class Solution
{
public:
  int mySqrt(int x)
  {
    if (x <= 1)
      return x;
    long long i = 0;
    while (i * i <= x)
      i++;
    return --i;
  }
};
