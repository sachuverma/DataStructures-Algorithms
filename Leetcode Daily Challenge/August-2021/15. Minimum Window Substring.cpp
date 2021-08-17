/*
Minimum Window Substring
========================

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 
Constraints:
m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 
Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

class Solution
{
public:
    bool same(unordered_map<char, int> &sMap, unordered_map<char, int> &tMap)
    {
        for (auto &i : tMap)
        {
            if (sMap[i.first] < i.second)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        int Size = s.size() + 1;
        int i = 0, j = 0;
        string ans, curr;

        unordered_map<char, int> tMap, sMap;
        for (auto &i : t)
            tMap[i]++;

        while (j < s.size())
        {
            sMap[s[j]]++;
            j++;

            while (same(sMap, tMap))
            {
                if (Size > j - i)
                {
                    Size = j - i;
                    ans = "";
                    for (int k = i; k < j; ++k)
                        ans += s[k];
                }
                sMap[s[i]]--;
                i++;
            }
        }

        return ans;
    }
};
