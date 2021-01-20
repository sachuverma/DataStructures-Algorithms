/*
Count Sorted Vowel Strings
==========================

Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

Example 1:
Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].

Example 2:
Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.

Example 3:
Input: n = 33
Output: 66045

Constraints:
1 <= n <= 50 

Hint #1  
For each character, its possible values will depend on the value of its previous character, because it needs to be not smaller than it.

Hint #2  
Think backtracking. Build a recursive function count(n, last_character) that counts the number of valid strings of length n and whose first characters are not less than last_character.

Hint #3  
In this recursive function, iterate on the possible characters for the first character, which will be all the vowels not less than last_character, and for each possible value c, increase the answer by count(n-1, c).
*/

class Solution
{
public:
  int countVowelStrings(int n)
  {
    vector<int> dp(5, 1);
    for (int i = 2; i <= n; ++i)
    {
      for (int j = 3; j >= 0; --j)
      {
        dp[j] += dp[j + 1];
      }
    }

    int ans = 0;
    for (auto &i : dp)
      ans += i;
    return ans;
  }
};
