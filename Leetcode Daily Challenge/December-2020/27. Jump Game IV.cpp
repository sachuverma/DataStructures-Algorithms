/*
Jump Game IV
============

Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

Example 1:
Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.

Example 2:
Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You don't need to jump.

Example 3:
Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.

Example 4:
Input: arr = [6,1,9]
Output: 2

Example 5:
Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
Output: 3

Constraints:
1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8

Hint #1  
Build a graph of n nodes where nodes are the indices of the array and edges for node i are nodes i+1, i-1, j where arr[i] == arr[j].

Hint #2  
Start bfs from node 0 and keep distance, answer is the distance when you reach onode n-1.
*/

class Solution
{
public:
  int minJumps(vector<int> &arr)
  {
    if (arr.size() == 1)
      return 0;
    int n = arr.size();
    vector<int> visited(n, 0);

    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < n; ++i)
    {
      if (adj.find(arr[i]) == adj.end())
        adj[arr[i]] = {i};
      else
        adj[arr[i]].push_back(i);
    }

    queue<int> q;
    q.push(0);
    visited[0] = 1;
    int ans = 0;

    while (q.size())
    {
      int size = q.size();
      for (int i = 0; i < size; ++i)
      {
        int idx = q.front();
        q.pop();
        if (idx == n - 1)
          return ans;

        if (idx - 1 >= 0 && idx - 1 < n && visited[idx - 1] == 0)
        {
          q.push(idx - 1);
          visited[idx - 1] = 1;
        }

        if (idx + 1 >= 0 && idx + 1 < n && visited[idx + 1] == 0)
        {
          q.push(idx + 1);
          visited[idx + 1] = 1;
        }

        if (adj.find(arr[idx]) != adj.end())
        {
          for (auto &i : adj[arr[idx]])
          {
            if (visited[i] == 0)
            {
              q.push(i);
              visited[i] = 1;
            }
          }
          adj.erase(arr[idx]);
        }
      }
      ans++;
    }
    return ans;
  }
};
