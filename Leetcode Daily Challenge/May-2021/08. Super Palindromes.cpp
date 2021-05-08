/*
Super Palindromes
=================

Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.

Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].

Example 1:
Input: left = "4", right = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.

Example 2:
Input: left = "1", right = "2"
Output: 1

Constraints:
1 <= left.length, right.length <= 18
left and right consist of only digits.
left and right cannot have leading zeros.
left and right represent integers in the range [1, 1018].
left is less than or equal to right.
*/

class Solution
{
public:
  bool isPalendrome(long long &n)
  {
    string st = to_string(n);
    int i = 0, j = st.size() - 1;
    while (i < j)
    {
      if (st[i++] != st[j--])
        return false;
    }
    return true;
  }

  int superpalindromesInRange(string l, string r)
  {
    int ans = 0, MAGIC = pow(10, 5);
    long long left = 0, right = 0;
    for (auto &i : l)
      left = left * 10 + (i - '0');
    for (auto &i : r)
      right = right * 10 + (i - '0');

    for (int k = 1; k < MAGIC; ++k)
    {
      long long R = 0;
      string S = to_string(k);
      for (int i = S.size() - 2; i >= 0; --i)
        S += S[i];
      for (auto &i : S)
        R = R * 10 + (i - '0');
      R = R * R;
      if (R > right)
        break;
      if (R >= left && isPalendrome(R))
        ans++;
    }

    for (int k = 1; k < MAGIC; ++k)
    {
      long long R = 0;
      string S = to_string(k);
      for (int i = S.size() - 1; i >= 0; --i)
        S += S[i];
      for (auto &i : S)
        R = R * 10 + (i - '0');
      R = R * R;
      if (R > right)
        break;
      if (R >= left && isPalendrome(R))
        ans++;
    }

    return ans;
  }
};
