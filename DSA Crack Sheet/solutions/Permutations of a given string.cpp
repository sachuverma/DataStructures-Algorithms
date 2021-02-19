/*
Permutations of a given string
==============================

Given a string S. The task is to print all permutations of a given string.

Input:
The first line of input contains an integer T, denoting the number of test cases. Each test case contains a single string S in capital letter.

Output:
For each test case, print all permutations of a given string S with single space and all permutations should be in lexicographically increasing order.

Constraints:
1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:
Input:
2
ABC
ABSG

Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA

Explanation:
Testcase 1: Given string ABC has permutations in 6 forms as ABC, ACB, BAC, BCA, CAB and CBA .
*/

#include <bits/stdc++.h>
using namespace std;

void permute(string str, string out, set<string> &ans)
{
  if (str.size() == 0)
  {
    ans.insert(out);
    return;
  }

  for (int i = 0; i < str.size(); i++)
  {
    permute(str.substr(1), out + str[0], ans);
    rotate(str.begin(), str.begin() + 1, str.end());
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    set<string> ans;
    permute(s, "", ans);

    for (auto &i : ans)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
