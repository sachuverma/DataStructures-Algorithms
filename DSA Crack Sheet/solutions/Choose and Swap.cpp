/*
Choose and Swap
===============

You are given a string s of lower case english alphabets. You can choose any two characters in the string and replace all the occurences of the first character with the second character and replace all the occurences of the second character with the first character. Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once.

Example 1:
Input:
A = "ccad"
Output: "aacd"
Explanation:
In ccad, we choose ‘a’ and ‘c’ and after 
doing the replacement operation once we get, 
aacd and this is the lexicographically
smallest string possible. 

Example 2:
Input:
A = "abba"
Output: "abba"
Explanation:
In abba, we can get baab after doing the 
replacement operation once for ‘a’ and ‘b’ 
but that is not lexicographically smaller 
than abba. So, the answer is abba. 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function chooseandswap() which takes the string A as input parameters and returns the lexicographically smallest string that is possible after doing the operation at most once.

Expected Time Complexity: O(|A|) length of the string A
Expected Auxiliary Space: O(1)

Constraints:
1<= |A| <=105
*/

string chooseandswap(string a)
{
  vector<int> first(256, INT_MAX);
  for (int i = 0; i < a.size(); ++i)
  {
    if (first[a[i]] > i)
      first[a[i]] = i;
  }

  char f = '0', s = '0';

  for (int i = 0; i < a.size(); ++i)
  {
    for (auto ch = 'a'; ch <= 'z'; ++ch)
    {
      if (ch < a[i] && first[ch] != INT_MAX && first[ch] > i)
      {
        f = ch;
        s = a[i];
        break;
      }
    }
    if (f != '0')
      break;
  }

  for (int i = 0; i < a.size(); ++i)
  {
    if (a[i] == f)
      a[i] = s;
    else if (a[i] == s)
      a[i] = f;
  }

  return a;
}