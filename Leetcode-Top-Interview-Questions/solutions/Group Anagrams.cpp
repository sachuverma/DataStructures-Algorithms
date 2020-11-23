/*
Group Anagrams
==============

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]


Constraints:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.
*/

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    unordered_map<string, vector<int>> indices;
    for (int i = 0; i < strs.size(); ++i)
    {
      auto s = strs[i];
      sort(s.begin(), s.end());
      indices[s].push_back(i);
    }
    vector<vector<string>> ans;
    for (auto it = indices.begin(); it != indices.end(); ++it)
    {
      auto arr = it->second;
      vector<string> sub_ans;
      for (auto idx : arr)
        sub_ans.push_back(strs[idx]);
      ans.push_back(sub_ans);
    }
    return ans;
  }
};
