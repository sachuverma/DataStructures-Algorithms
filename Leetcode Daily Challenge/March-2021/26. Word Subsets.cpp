/*
Word Subsets
===========

We are given two arrays A and B of words.  Each word is a string of lowercase letters.

Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.  For example, "wrr" is a subset of "warrior", but is not a subset of "world".

Now say a word a from A is universal if for every b in B, b is a subset of a. 

Return a list of all universal words in A.  You can return the words in any order.

Example 1:
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
Output: ["facebook","google","leetcode"]

Example 2:
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
Output: ["apple","google","leetcode"]

Example 3:
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
Output: ["facebook","google"]

Example 4:
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
Output: ["google","leetcode"]

Example 5:
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
Output: ["facebook","leetcode"]

Note:
1 <= A.length, B.length <= 10000
1 <= A[i].length, B[i].length <= 10
A[i] and B[i] consist only of lowercase letters.
All words in A[i] are unique: there isn't i != j with A[i] == A[j]
*/

class Solution
{
public:
  vector<string> wordSubsets(vector<string> &A, vector<string> &B)
  {
    vector<int> bfreqs(26, 0); // these freq must be present in word of A to become universal
    for (auto &word : B)
    {
      vector<int> arr(26, 0);
      for (auto &i : word)
        arr[i - 'a']++;
      for (int i = 0; i < 26; ++i)
      {
        bfreqs[i] = max(bfreqs[i], arr[i]);
      }
    }

    vector<string> ans;
    for (auto &word : A)
    {
      vector<int> afreqs(26, 0);
      for (auto &i : word)
        afreqs[i - 'a']++;
      int universal = 1;
      for (int i = 0; i < 26; ++i)
      {
        if (afreqs[i] < bfreqs[i])
        {
          universal = 0;
          break;
        }
      }
      if (universal)
        ans.push_back(word);
    }
    return ans;
  }
};
