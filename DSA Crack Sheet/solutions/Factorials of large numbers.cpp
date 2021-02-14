/*
Factorials of large numbers
===========================

Given an integer, the task is to find factorial of the number.

Input:
The first line of input contains an integer T denoting the number of test cases.  
The first line of each test case is N,the number whose factorial is to be found

Output:
Print the factorial of the number in separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000

Example:
Input:
3
5
10
2

Output:
120
3628800
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
    int n;
    cin >> n;
    string ans = "1";
    for (int i = 2; i <= n; ++i)
    {
      int carry = 0;
      for (auto &ch : ans)
      {
        int num = ch - '0';
        num = i * num;
        num += carry;
        int digit = num % 10;
        ch = (digit + '0');
        carry = num / 10;
      }

      while (carry)
      {
        int digit = carry % 10;
        carry = carry / 10;
        ans += to_string(digit);
      }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
  return 0;
}
