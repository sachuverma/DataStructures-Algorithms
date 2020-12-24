/*
Next Greater Element III
========================

Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

Example 1:
Input: n = 12
Output: 21

Example 2:
Input: n = 21
Output: -1

Constraints:
1 <= n <= 231 - 1
*/

class Solution
{
public:
  int nextGreaterElement(int n)
  {
    vector<int> digits;
    while (n)
    {
      int digit = n % 10;
      digits.insert(digits.begin(), digit);
      n /= 10;
    }

    if (next_permutation(digits.begin(), digits.end()))
    {
      long long number = 0;

      for (int i = 0; i < digits.size(); ++i)
        number = number * 10 + digits[i];

      if (number > INT_MAX)
        return -1;
      return number;
    }
    else
      return -1;
  }
};
