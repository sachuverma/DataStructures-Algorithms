/*
Longest String Chain
====================

Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2. For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

Example 1:
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chain is "a","ba","bda","bdca".

Example 2:
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5

Constraints:
1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of English lowercase letters.

Hint #1  
Instead of adding a character, try deleting a character to form a chain in reverse.

Hint #2  
For each word in order of length, for each word2 which is word with one character removed, length[word2] = max(length[word2], length[word] + 1).
*/

class Solution
{
public:
  int dfs(string word, unordered_set<string> &words, unordered_map<string, int> &memo)
  {

    if (memo.find(word) != memo.end())
      return memo[word];
    int ans = 1;

    for (int i = 0; i < word.size(); ++i)
    {
      string curr = word.substr(0, i) + word.substr(i + 1);

      if (words.find(curr) != words.end())
        ans = max(ans, 1 + dfs(curr, words, memo));
    }

    return memo[word] = ans;
  }

  int longestStrChain(vector<string> &arr)
  {
    unordered_set<string> words(arr.begin(), arr.end());
    unordered_map<string, int> memo;

    int ans = 0;
    for (auto &i : arr)
      ans = max(ans, dfs(i, words, memo));
    return ans;
  }
};
