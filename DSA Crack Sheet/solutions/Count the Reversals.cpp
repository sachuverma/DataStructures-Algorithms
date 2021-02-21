/*
Count the Reversals
===================

Given a string S consisting only of opening and closing curly brackets '{' and '}' find out the minimum number of reversals required to make a balanced expression.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases
follow. The first line of each test case contains a string S consisting only of { and }.
Output:
Print out minimum reversals required to make S balanced. If it cannot be balanced, then print -1.

Constraints
1 <= T <= 100
0 <= |S| <= 50

Examples
Input:
4
}{{}}{{{
{{}}}}
{{}{{{}{{}}{{
{{{{}}}}
Output:
3
1
-1
0

Explanation:
Testcase 1: For the given string }{{}}{{{ since the length is even we just need to count the number of openning brackets('{') suppose denoted by 'm' and closing brackest('}') suppose dentoed by 'n' after removing highlighted ones. After counting compute ceil(m/2) + ceil(n/2).
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
    int left = 0, right = 0;
    for (auto &i : s)
    {
      if (i == '{')
        left++;
      else
      {
        if (left == 0)
          right++;
        else
          left--;
      }
    }

    if ((left + right) % 2)
      cout << -1 << endl;
    else
    {
      int ans = 0;
      if (left % 2)
        ans = 2;
      ans += left / 2 + right / 2;

      cout << ans << endl;
    }
  }
  return 0;
}
