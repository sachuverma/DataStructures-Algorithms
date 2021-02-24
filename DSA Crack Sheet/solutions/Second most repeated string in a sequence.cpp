/*
Second most repeated string in a sequence
==========================================

Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Example 1:
Input:
N = 6
arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
Output: bbb
Explanation: "bbb" is the second most 
occurring string with frequency 2.

Example 2:
Input: 
N = 6
arr[] = {geek, for, geek, for, geek, aaa}
Output: for
Explanation: "for" is the second most
occurring string with frequency 2.

Your Task:
You don't need to read input or print anything. Your task is to complete the function secFrequent() which takes the string array arr[] and its size N as inputs and returns the second most frequent string in the array.

Expected Time Complexity: O(N*max(|Si|).
Expected Auxiliary Space: O(N*max(|Si|).

Constraints:
1<=N<=103
*/

string secFrequent(string arr[], int n)
{
  priority_queue<pair<int, string>> pq;
  unordered_map<string, int> m;
  for (int i = 0; i < n; ++i)
    m[arr[i]]++;
  for (auto &i : m)
    pq.push({i.second, i.first});
  pq.pop();
  return pq.top().second;
}
