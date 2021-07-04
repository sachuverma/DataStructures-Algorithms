/*
Count Vowels Permutation
========================

Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".

Example 2:
Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".

Example 3: 
Input: n = 5
Output: 68

Constraints:
1 <= n <= 2 * 10^4

Hint #1  
Use dynamic programming.

Hint #2  
Let dp[i][j] be the number of strings of length i that ends with the j-th vowel.

Hint #3  
Deduce the recurrence from the given relations between vowels.
*/

class Solution
{
public:
  int M = 1e9 + 7;

  int countVowelPermutation(int n)
  {
    long long a = 1, e = 1, i = 1, o = 1, u = 1;

    for (int j = 1; j < n; ++j)
    {
      long long A = 0, E = 0, I = 0, O = 0, U = 0;
      A = e + i + u;
      E = a + i;
      I = e + o;
      O = i;
      U = i + o;

      a = A % M;
      e = E % M;
      i = I % M;
      o = O % M;
      u = U % M;
    }

    return (a % M + e % M + i % M + o % M + u % M) % M;
  }
};