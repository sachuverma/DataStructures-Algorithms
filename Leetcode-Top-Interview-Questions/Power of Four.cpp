/*
Power of Four
=============

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:
Input: 16
Output: true

Example 2:
Input: 5
Output: false

Follow up: Could you solve it without loops/recursion?
*/

class Solution
{
public:
  bool isPowerOfFour(int num)
  {
    return num > 0 && (log10(num) / log10(4)) == floor((log10(num) / log10(4)));
  }
};
