/*
Reorganize String
=================

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

Example 1:
Input: s = "aab"
Output: "aba"

Example 2:
Input: s = "aaab"
Output: ""

Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.
*/

string reorganizeString(string &A)
{
  int n = A.size();
  unordered_map<char, int> C;
  for (auto &i : A)
  {
    C[i]++;
    if (C[i] > (n + 1) / 2)
      return "";
  }

  priority_queue<pair<int, char>> pq;
  for (auto &i : C)
    pq.push({i.second, i.first});

  string B;
  while (pq.size())
  {
    auto First = pq.top();
    pq.pop();
    auto Second = pq.top();
    pq.pop();

    if (First.first > 0)
    {
      B += (First.second);
      First.first--;
    }
    else
      break;

    if (Second.first > 0)
    {
      B += (Second.second);
      Second.first--;
    }
    else
      break;

    pq.push({First.first, First.second});
    pq.push({Second.first, Second.second});
  }

  return B;
}