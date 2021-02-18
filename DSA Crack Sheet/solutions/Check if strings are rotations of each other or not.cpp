/*
Check if strings are rotations of each other or not
====================================================

Given two strings s1 and s2. The task is to check if s2 is a rotated version of the string s1. The characters in the strings are in lowercase.

Example 1:
Input:
geeksforgeeks
forgeeksgeeks
Output: 
1
Explanation: s1 is geeksforgeeks, s2 is
forgeeksgeeks. Clearly, s2 is a rotated
version of s1 as s2 can be obtained by
left-rotating s1 by 5 units.

Example 2:
Input:
mightandmagic
andmagicmigth
Output: 
0
Explanation: Here with any amount of
rotation s2 can't be obtained by s1.

Your Task:
The task is to complete the function areRotations() which checks if the two strings are rotations of each other. The function returns true if string 1 can be obtained by rotating string 2, else it returns false.

Expected Time Complexity: O(N).
Expected Space Complexity: O(N).
Note: N = |s1|.

Constraints:
1 <= |s1|, |s2| <= 107
*/

/*  Function to check if two strings are rotations of each other
*   s1, s2: are the input strings
*/
bool areRotations(string s1, string s2)
{
  if (s1.size() != s2.size())
    return false;
  auto temp = s1 + s1;
  for (int i = 0; i < temp.size(); ++i)
  {
    if (temp[i] == s2[0] && temp.substr(i, s2.size()) == s2)
      return true;
  }
  return false;
}