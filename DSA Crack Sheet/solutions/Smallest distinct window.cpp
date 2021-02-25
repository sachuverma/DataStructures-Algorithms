/*
Smallest distinct window
========================

Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.

Example 1:
Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"

Example 2:
Input : "aaab"
Output : 2
Explanation : Sub-string -> "ab"

Example 3:
Input : "GEEKSGEEKSFOR"
Output : 8
Explanation : Sub-string -> "GEEKSFOR"

Your Task:  
You don't need to read input or print anything. Your task is to complete the function findSubString() which takes the string  S as inputs and returns the length of the smallest such string.

Expected Time Complexity: O(256.N)
Expected Auxiliary Space: O(256)

Constraints:
1 ≤ |S| ≤ 105
String may contain both type of English Alphabets.
*/

string findSubString(string str)
{
  int n = str.size();
  int dist_count = 0;
  bool visited[256] = {false};

  for (int i = 0; i < n; i++)
  {
    if (visited[str[i]] == false)
    {
      visited[str[i]] = true;
      dist_count++;
    }
  }

  int start = 0, start_index = -1, min_len = INT_MAX;

  int count = 0;
  int curr_count[256] = {0};

  for (int i = 0; i < n; ++i)
  {
    curr_count[str[i]]++;
    if (curr_count[str[i]] == 1)
      count++;
    if (count == dist_count)
    {
      while (curr_count[str[start]] > 1)
      {
        if (curr_count[str[start]] > 1)
          curr_count[str[start]]--;
        start++;
      }

      int len_window = i - start + 1;
      if (min_len > len_window)
      {
        min_len = len_window;
        start_index = start;
      }
    }
  }

  return str.substr(start_index, min_len);
}
