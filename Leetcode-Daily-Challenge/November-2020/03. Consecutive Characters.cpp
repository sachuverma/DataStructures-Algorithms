/*
Consecutive Characters
======================

Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return the power of the string.


Example 1:
Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.

Example 2:
Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.

Example 3:
Input: s = "triplepillooooow"
Output: 5

Example 4:
Input: s = "hooraaaaaaaaaaay"
Output: 11

Example 5:
Input: s = "tourist"
Output: 1


Constraints:
1 <= s.length <= 500
s contains only lowercase English letters.

Hint #1  
Keep an array power where power[i] is the maximum power of the i-th character.

Hint #2  
The answer is max(power[i]).
*/

class Solution
{
public:
  int maxPower(string s)
  {
    if (s.size() == 0)
      return 0;

    char prev = s[0];
    int count = 1, ans = 1;
    for (int i = 1; i < s.size(); ++i)
    {
      int curr = s[i];
      if (curr == prev)
      {
        count++;
        ans = max(ans, count);
      }
      else
      {
        prev = curr;
        count = 1;
      }
    }
    return ans;
  }
};
