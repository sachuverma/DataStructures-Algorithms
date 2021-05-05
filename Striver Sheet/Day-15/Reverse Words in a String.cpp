/*
Reverse Words in a String
=========================

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Example 4:
Input: s = "  Bob    Loves  Alice   "
Output: "Alice Loves Bob"

Example 5:
Input: s = "Alice does not even like bob"
Output: "bob like even not does Alice"

Constraints:
1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.

Follow up: Could you solve it in-place with O(1) extra space?
*/

class Solution
{
public:
  string reverseWords(string s)
  {
    int n = s.size();
    reverse(s.begin(), s.end());
    int i = 0, j = 0;
    while (j < n)
    {
      i = j;
      while (j < n && s[j] != ' ')
        j++;
      reverse(s.begin() + i, s.begin() + j);
      j++;
    }

    i = 0;
    j = 0;
    while (j < n)
    {
      while (j < n && s[j] == ' ')
        j++; // skip spaces
      while (j < n && s[j] != ' ')
        s[i++] = s[j++]; // keep non spaces
      while (j < n && s[j] == ' ')
        j++; // skip spaces
      if (j < n)
        s[i++] = ' '; // keep only one space
    }
    return s.substr(0, i);
  }
};
