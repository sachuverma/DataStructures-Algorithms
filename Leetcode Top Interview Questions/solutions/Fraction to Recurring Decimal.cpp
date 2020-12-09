/*
Fraction to Recurring Decimal
=============================

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.


Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:
Input: numerator = 2, denominator = 1
Output: "2"

Example 3:
Input: numerator = 2, denominator = 3
Output: "0.(6)"

Example 4:
Input: numerator = 4, denominator = 333
Output: "0.(012)"

Example 5:
Input: numerator = 1, denominator = 5
Output: "0.2"

Constraints:
-231 <= numerator, denominator <= 231 - 1
denominator != 0

Hint #1  
No scary math, just apply elementary math knowledge. Still remember how to perform a long division?

Hint #2  
Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?

Hint #3  
Notice that once the remainder starts repeating, so does the divided result.

Hint #4  
Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.
*/

class Solution
{
public:
  string fractionToDecimal(int64_t n, int64_t d)
  {
    if (n == 0)
      return "0";

    string res;
    if (n < 0 ^ d < 0)
      res += '-';
    n = abs(n), d = abs(d);
    res += to_string(n / d);
    if (n % d == 0)
      return res;

    res += '.';
    unordered_map<int, int> map;
    for (int64_t r = n % d; r; r %= d)
    {
      if (map.count(r) > 0)
      {
        res.insert(map[r], 1, '(');
        res += ')';
        break;
      }
      map[r] = res.size();
      r *= 10;
      res += to_string(r / d);
    }

    return res;
  }
};
