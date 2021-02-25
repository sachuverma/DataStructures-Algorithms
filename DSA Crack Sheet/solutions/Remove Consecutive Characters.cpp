/*
Remove Consecutive Characters
=============================

Given a string S delete the characters which are appearing more than once consecutively.

Example 1:
Input:
S = aabb
Output:  ab 
Explanation: 'a' at 2nd position is
appearing 2nd time consecutively.
Similiar explanation for b at
4th position.

Example 2:
Input:
S = aabaa
Output:  aba
Explanation: 'a' at 2nd position is
appearing 2nd time consecutively.
'a' at fifth position is appearing
2nd time consecutively.

Your Task:
You dont need to read input or print anything. Complete the function removeConsecutiveCharacter() which accepts a string as input parameter and returns modified string.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(|S|).

Constraints:
1<=|S|<=105
All characters are lowercase alphabets.
*/

string removeConsecutiveCharacter(string S)
{
  string ans;
  char prev = '\0';
  for (auto &i : S)
  {
    if (prev == i)
      continue;
    ans += i;
    prev = i;
  }
  return ans;
}
