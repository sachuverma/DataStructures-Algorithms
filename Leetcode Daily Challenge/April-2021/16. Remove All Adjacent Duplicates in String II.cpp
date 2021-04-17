/*
Remove All Adjacent Duplicates in String II
============================================

You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

Example 1:
Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.

Example 2:
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"

Example 3:
Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"

Constraints:
1 <= s.length <= 105
2 <= k <= 104
s only contains lower case English letters.

Hint #1  
Use a stack to store the characters, when there are k same characters, delete them.

Hint #2  
To make it more efficient, use a pair to store the value and the count of each character.
*/

class Solution
{
public:
  string removeDuplicates(string str, int k)
  {
    stack<char> s;
    stack<int> counts;

    for (int i = 0; i < str.size(); ++i)
    {
      if (s.size() == 0)
      {
        s.push(str[i]);
        counts.push(1);
      }
      else if (s.top() == str[i] && counts.top() == k - 1)
      {
        for (int j = 0; j < k - 1; ++j)
          s.pop();
        counts.pop();
      }
      else
      {
        if (s.top() == str[i])
        {
          int c = counts.top();
          counts.pop();
          counts.push(c + 1);
        }
        else
          counts.push(1);
        s.push(str[i]);
      }
    }

    string ans;
    while (s.size())
    {
      ans = s.top() + ans;
      s.pop();
    }
    return ans;
  }
};