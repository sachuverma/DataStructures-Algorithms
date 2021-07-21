/*
Push Dominoes
=============

There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.

Example 1:
Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.

Example 2:
Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."

Constraints:
n == dominoes.length
1 <= n <= 105
dominoes[i] is either 'L', 'R', or '.'.
*/

class Solution
{
public:
  string pushDominoes(string s)
  {
    vector<int> left, right;

    for (int i = 0; i < s.size(); ++i)
    {
      if (s[i] == 'L')
        left.push_back(i);
      if (s[i] == 'R')
        right.push_back(i);
    }

    for (int i = 0; i < right.size(); ++i)
    {

      int rightIndex = right[i];

      auto it = upper_bound(left.begin(), left.end(), rightIndex);
      auto itR = upper_bound(right.begin(), right.end(), rightIndex);

      if (it == left.end())
        break;

      if (itR != right.end() && *it > *itR)
        continue;

      int leftIndex = *it;
      int e = leftIndex - rightIndex - 1;

      for (int j = 1; j <= e / 2; ++j)
        s[rightIndex + j] = 'R';
      for (int j = 1; j <= e / 2; ++j)
        s[leftIndex - j] = 'L';
    }

    right.push_back(s.size());
    left.insert(left.begin(), -1);

    for (int i = 1; i < left.size(); ++i)
    {
      int leftPrev = left[i - 1];
      int leftNext = left[i];

      auto it = upper_bound(right.begin(), right.end(), leftPrev);
      if (it != right.end() && *it <= leftNext)
        continue;
      for (int j = leftPrev + 1; j <= leftNext - 1; ++j)
        s[j] = 'L';
    }

    for (int i = 0; i < right.size() - 1; ++i)
    {
      int rightPrev = right[i];
      int rightNext = right[i + 1];

      auto it = upper_bound(left.begin(), left.end(), rightPrev);
      if (it != left.end() && *it <= rightNext)
        continue;
      for (int j = rightPrev + 1; j <= rightNext - 1; ++j)
        s[j] = 'R';
    }

    return s;
  }
};
