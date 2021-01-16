/*
Word Ladder
===========

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words such that:

The first word in the sequence is beginWord.
The last word in the sequence is endWord.
Only one letter is different between each adjacent pair of words in the sequence.
Every word in the sequence is in wordList.
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog" with 5 words.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no possible transformation.

Constraints:
1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the strings in wordList are unique.
*/

class Solution
{
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {
    unordered_set<string> left(wordList.begin(), wordList.end());

    if (left.find(endWord) == left.end())
      return 0;
    int ans = 0;

    queue<string> pending;
    pending.push(beginWord);

    while (pending.size())
    {
      int size = pending.size();
      ans++;

      for (int i = 0; i < size; ++i)
      {
        auto curr = pending.front();
        pending.pop();

        for (int i = 0; i < curr.size(); ++i)
        {
          auto temp = curr;
          for (auto c = 'a'; c <= 'z'; ++c)
          {
            temp[i] = c;
            if (temp == curr)
              continue;
            if (temp == endWord)
              return ans + 1;
            if (left.find(temp) != left.end())
            {
              left.erase(temp);
              pending.push(temp);
            }
          }
        }
      }
    }

    return 0;
  }
};
