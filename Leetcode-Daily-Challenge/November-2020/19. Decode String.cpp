/*
Decode String
=============

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Example 4:
Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"

Constraints:
1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/

class Solution
{
public:
  string decodeString(string s)
  {
    stack<int> count;
    stack<string> substrings;
    string result;

    int index = 0;
    while (index < s.size())
    {
      if (isdigit(s[index]))
      {
        int num = 0;
        while (isdigit(s[index]))
        {
          num = num * 10 + (s[index] - '0');
          index++;
        }
        count.push(num);
      }
      else if (s[index] == '[')
      {
        substrings.push(result);
        result = "";
        index++;
      }
      else if (s[index] == ']')
      {
        string temp = substrings.top();
        substrings.pop();
        int num = count.top();
        count.pop();
        while (num--)
          temp += result;
        result = temp;
        index++;
      }
      else
      {
        result += s[index];
        index++;
      }
    }

    return result;
  }
};
