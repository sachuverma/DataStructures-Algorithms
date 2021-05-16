/*
Detect cycle in an undirected graph
===================================

Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Example 1:
Output: 1
Explanation: 1->2->3->4->1 is a cycle.

Example 2:
Output: 0
Explanation: No cycle in the graph.

Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not.

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 105
*/

class Solution
{
public:
  bool dfs(int curr, vector<int> adj[], vector<int> &vis, int par)
  {
    for (auto &i : adj[curr])
    {
      if (i != par)
      {
        if (vis[i])
          return true;
        vis[i] = 1;
        if (dfs(i, adj, vis, curr))
          return true;
      }
    }
    return false;
  }

  //Function to detect cycle in an undirected graph.
  bool isCycle(int V, vector<int> adj[])
  {
    vector<int> visited(V, 0);
    for (int i = 0; i < V; ++i)
    {
      if (!visited[i])
      {
        visited[i] = 1;
        if (dfs(i, adj, visited, -1))
          return true;
      }
    }
    return false;
  }
};
