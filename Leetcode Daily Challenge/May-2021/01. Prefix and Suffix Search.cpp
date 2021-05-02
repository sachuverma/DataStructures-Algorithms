/*
Prefix and Suffix Search
========================

Design a special dictionary which has some words and allows you to search the words in it by a prefix and a suffix.

Implement the WordFilter class:

WordFilter(string[] words) Initializes the object with the words in the dictionary.
f(string prefix, string suffix) Returns the index of the word in the dictionary which has the prefix prefix and the suffix suffix. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.

Example 1:
Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]
Explanation
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = 'e".

Constraints:
1 <= words.length <= 15000
1 <= words[i].length <= 10
1 <= prefix.length, suffix.length <= 10
words[i], prefix and suffix consist of lower-case English letters only.
At most 15000 calls will be made to the function f.

Hint #1  
For a word like "test", consider "#test", "t#test", "st#test", "est#test", "test#test". Then if we have a query like prefix = "te", suffix = "t", we can find it by searching for something we've inserted starting with "t#te".
*/

class WordFilter
{
public:
  unordered_map<string, int> comb;

  WordFilter(vector<string> &words)
  {
    for (int it = 0; it != words.size(); ++it)
    {
      string word = words[it];
      for (int i = 0; i < word.size(); ++i)
      {
        for (int j = 0; j < word.size(); ++j)
        {
          string curr = word.substr(0, i + 1) + "#" + word.substr(j);
          comb[curr] = it;
        }
      }
    }
  }

  int f(string prefix, string suffix)
  {
    string curr = prefix + "#" + suffix;
    return comb.find(curr) != comb.end() ? comb[curr] : -1;
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
