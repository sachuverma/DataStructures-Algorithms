/*
Rearrange characters
====================

Given a string S with repeated characters (only lowercase). The task is to rearrange characters in a string such that no two adjacent characters are same.

Note : It may be assumed that the string has only lowercase English alphabets.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a single line containing a string of lowercase english alphabets.

Output:
For each test case in a new line print "1" (without quotes) if the generated string doesn't contains any same adjacent characters, else if no such string is possible to be made print "0" (without quotes).

Constraints:
1 <= T <= 100
1 <= length of string <= 104

Example:
Input:
3
geeksforgeeks
bbbabaaacd
bbbbb
Output:
1
1
0

Explanation:
Testcase 1: All the repeated characters of the given string can be rearranged so that no adjacent characters in the string is equal.
Testcase 3: Repeated characters in the string cannot be rearranged such that there should not be any adjacent repeated character.
*/

#include <bits/stdc++.h>
using namespace std;

int solve()
{
  string s;
  cin >> s;
  int size = (s.size() + 1) / 2;
  unordered_map<char, int> f;
  for (auto &i : s)
    f[i]++;
  for (auto &i : f)
  {
    if (i.second > size)
    {
      return 0;
    }
  }
  return 1;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    cout << solve() << endl;
  }
  return 0;
}
