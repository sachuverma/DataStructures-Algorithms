/*
Detect cycle in a directed graph
================================

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

Example 1:
Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:
Output: 0
Explanation: no cycle in the graph

Your task:
You don’t need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)

Constraints:
1 ≤ V, E ≤ 105
*/

class Solution
{
public:
  bool dfs(int curr, vector<int> adj[], vector<int> &rec, vector<int> &vis)
  {
    if (rec[curr])
      return true;

    rec[curr] = 1;

    for (auto &i : adj[curr])
    {
      if (!vis[i] && dfs(i, adj, rec, vis))
        return true;
    }

    vis[curr] = 1;
    rec[curr] = 0;
    return false;
  }

  //Function to detect cycle in a directed graph.
  bool isCyclic(int V, vector<int> adj[])
  {
    vector<int> recStack(V, 0), visited(V, 0);
    for (int i = 0; i < V; ++i)
    {
      if (dfs(i, adj, recStack, visited))
        return true;
    }
    return false;
  }
};
