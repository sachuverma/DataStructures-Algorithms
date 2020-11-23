/*
Most Common Word
================

Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

 

Example:

Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.


Note:
1 <= paragraph.length <= 1000.
0 <= banned.length <= 100.
1 <= banned[i].length <= 10.
The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
There are no hyphens or hyphenated words.
Words only consist of letters, never apostrophes or other punctuation symbols.
*/

class Solution
{
public:
  string mostCommonWord(string paragraph, vector<string> &banned)
  {
    unordered_map<string, int> para;
    unordered_map<string, int> ban;
    transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);

    for (auto word : banned)
    {
      transform(word.begin(), word.end(), word.begin(), ::tolower);
      ban[word]++;
    }

    string word = "";
    for (auto x : paragraph)
    {
      if (!isalnum(x))
      {
        if (word != "" && word != " ")
          para[word]++;
        word = "";
      }
      else
        word = word + x;
    }

    if (word != "" && word != " ")
      para[word]++;
    string ans;
    int curr_max = INT_MIN;

    for (auto it = para.begin(); it != para.end(); ++it)
    {
      if (!ban[it->first] && curr_max < it->second)
      {
        curr_max = it->second;
        ans = it->first;
      }
    }
    return ans;
  }
};
