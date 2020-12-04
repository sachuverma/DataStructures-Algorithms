/*
Word Ladder
===========

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class Solution
{
public:
  int ladderLength(string begin, string end, vector<string> &wordList)
  {
    unordered_set<string> nonVisited(wordList.begin(), wordList.end());
    if (nonVisited.find(end) == nonVisited.end())
      return 0;

    queue<string> pending;
    pending.push(begin);
    int steps = 1;

    while (pending.size())
    {
      int size = pending.size();
      for (int i = 0; i < size; ++i)
      {
        auto word = pending.front();
        pending.pop();
        for (int j = 0; j < word.size(); ++j)
        {
          char originalChar = word[j];
          for (char c = 'a'; c <= 'z'; ++c)
          {
            if (word[j] == c)
              continue;
            word[j] = c;
            if (word == end)
              return steps + 1;
            if (nonVisited.find(word) != nonVisited.end())
            {
              nonVisited.erase(word);
              pending.push(word);
            }
          }
          word[j] = originalChar;
        }
      }
      steps++;
    }
    return 0;
  }
};
