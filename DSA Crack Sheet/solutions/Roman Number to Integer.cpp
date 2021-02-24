/*
Roman Number to Integer
=======================

Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:
Input:
s = V
Output: 5

Example 2:
Input:
s = III 
Output: 3
Your Task:
Complete the function romanToDecimal() which takes an string as input parameter and returns the equivalent decimal number. 

Expected Time Complexity: O(|S|), |S| = length of string S.
Expected Auxiliary Space: O(1)

Constraints:
1<=roman no range<=3999
*/

// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int romanToDecimal(string &s)
{
  unordered_map<char, pair<int, int>> m;
  m['I'] = {1, 1};
  m['V'] = {5, 2};
  m['X'] = {10, 3};
  m['L'] = {50, 4};
  m['C'] = {100, 5};
  m['D'] = {500, 6};
  m['M'] = {1000, 7};

  if (s.size() == 0)
    return 0;

  int ans = m[s[0]].first;
  for (int i = 1; i < s.size(); ++i)
  {
    if (m[s[i - 1]].second < m[s[i]].second)
    {
      ans = ans - 2 * (m[s[i - 1]].first) + m[s[i]].first;
    }
    else
    {
      ans = ans + m[s[i]].first;
    }
  }

  return ans;
}
