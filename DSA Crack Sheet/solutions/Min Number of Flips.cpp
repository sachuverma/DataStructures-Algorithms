/*
Min Number of Flips
===================

Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.

Examples:
Input : str = “001”
Output : 1
Minimum number of flips required = 1
We can flip 1st bit from 0 to 1 

Input : str = “0001010111”
Output : 2
Minimum number of flips required = 2
We can flip 2nd bit from 0 to 1 and 9th 
bit from 1 to 0 to make alternate 
string “0101010101”.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of one line. The line contains a string of 0's and 1's.
Output:
Minimum number of characters to be removed to make string alternate.

Constraints:
1 ≤ T ≤ 100
1 ≤ string length ≤ 1000

Example:
Input
2
01010
1111
Output
0
2
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    int ans1 = 0, ans2 = 0;

    int i = 0;
    while (i < s.size())
    {
      if (i % 2 && s[i] == '0')
        ans1++;
      else if (i % 2 == 0 && s[i] == '1')
        ans1++;
      i++;
    }

    i = 0;
    while (i < s.size())
    {
      if (i % 2 == 0 && s[i] == '0')
        ans2++;
      else if (i % 2 && s[i] == '1')
        ans2++;
      i++;
    }

    cout << min(ans1, ans2) << endl;
  }
  return 0;
}
