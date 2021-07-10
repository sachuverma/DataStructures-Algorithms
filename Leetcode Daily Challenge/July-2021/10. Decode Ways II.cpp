/*
Decode Ways II
==============

A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

In addition to the mapping above, an encoded message may contain the '*' character, which can represent any digit from '1' to '9' ('0' is excluded). For example, the encoded message "1*" may represent any of the encoded messages "11", "12", "13", "14", "15", "16", "17", "18", or "19". Decoding "1*" is equivalent to decoding any of the encoded messages it can represent.

Given a string s containing digits and the '*' character, return the number of ways to decode it.

Since the answer may be very large, return it modulo 109 + 7.

Example 1:
Input: s = "*"
Output: 9
Explanation: The encoded message can represent any of the encoded messages "1", "2", "3", "4", "5", "6", "7", "8", or "9".
Each of these can be decoded to the strings "A", "B", "C", "D", "E", "F", "G", "H", and "I" respectively.
Hence, there are a total of 9 ways to decode "*".

Example 2:
Input: s = "1*"
Output: 18
Explanation: The encoded message can represent any of the encoded messages "11", "12", "13", "14", "15", "16", "17", "18", or "19".
Each of these encoded messages have 2 ways to be decoded (e.g. "11" can be decoded to "AA" or "K").
Hence, there are a total of 9 * 2 = 18 ways to decode "1*".

Example 3:
Input: s = "2*"
Output: 15
Explanation: The encoded message can represent any of the encoded messages "21", "22", "23", "24", "25", "26", "27", "28", or "29".
"21", "22", "23", "24", "25", and "26" have 2 ways of being decoded, but "27", "28", and "29" only have 1 way.
Hence, there are a total of (6 * 2) + (3 * 1) = 12 + 3 = 15 ways to decode "2*".

Constraints:
1 <= s.length <= 105
s[i] is a digit or '*'
*/

class Solution
{
public:
  int M = 1e9 + 7;
  vector<long long> memo;

  long long dfs(string &s, int i)
  {
    if (i >= s.size())
      return 1;
    long long ans = 0;

    if (s[i] == '0')
      return 0;
    if (memo[i] != -1)
      return memo[i];

    if (s[i] == '*')
      ans += 9 * dfs(s, i + 1);
    else
      ans += dfs(s, i + 1);

    ans = ans % M;

    if (i + 1 < s.size())
    {
      if (s[i] == '*' && s[i + 1] == '*')
        ans += 15 * dfs(s, i + 2);

      else if (s[i] == '*')
      {
        if (s[i + 1] >= '0' && s[i + 1] <= '6')
          ans += 2 * dfs(s, i + 2);
        else
          ans += 1 * dfs(s, i + 2);
      }

      else if (s[i + 1] == '*')
      {
        if (s[i] == '1')
          ans += 9 * dfs(s, i + 2);
        else if (s[i] == '2')
          ans += 6 * dfs(s, i + 2);
      }

      else if (s[i] == '1' && s[i + 1] >= '0' && s[i + 1] <= '9')
        ans += dfs(s, i + 2);
      else if (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6')
        ans += dfs(s, i + 2);
    }

    ans = ans % M;
    return memo[i] = ans;
  }

  int numDecodings(string s)
  {
    memo = vector<long long>(s.size() + 1, -1);
    return dfs(s, 0);
  }
};