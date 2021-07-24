/*
Word Ladder II
==============

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].


Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 
Constraints:
1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 1000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, vector<string>& wL) {
      
      // push all words in set to make is easy to search
      unordered_set<string> words(wL.begin(), wL.end());
      
      // ans to store all min paths
      vector<vector<string>> ans;
      int path = INT_MAX;
      
      // push a path in queue
      // in starting path only has one node
      queue<vector<string>> q; q.push({ start });
      
      // erased from set, means node is maked visited
      words.erase(start);
      
      
      while(q.size()) {
        auto curr = q.front(); 
        q.pop();
        
        // stop this path, it's not valid
        if(curr.size() > path) continue;
        auto prev = curr.back();
        words.erase(prev);
        
        // we reached end
        // if curr path combination size is less than prev than clear prev ans
        if(prev == end) {
          if(curr.size() < path) ans.clear();
          ans.push_back(curr);
          path = curr.size();
          continue;
        }
        
        // generate all next combinations of most recent node in path vector
        for(int i=0; i<prev.size(); ++i) {
          for(char c='a'; c<='z'; ++c){
            string copy = prev;
            copy[i] = c;
            
            // if this next node is present in set, we can visite
            // hence push it in queue
            if(c != prev[i] && words.count(copy)) {
              curr.push_back(copy);
              q.push(curr);
              curr.pop_back();
            }
          }
        }
      }
      
      return ans;
    }
};