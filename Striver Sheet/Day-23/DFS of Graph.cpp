/*
DFS of Graph
============

Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph..

Example 1:
Input:
Output: 0 1 2 4 3
Explanation: 
0 is connected to 1, 2, 4.
1 is connected to 0.
2 is connected to 0.
3 is connected to 0.
4 is connected to 0, 3.
so starting from 0, it will go to 1 then 2
then 4, and then from 4 to 3.
Thus dfs will be 0 1 2 4 3.

Example 2:
Input:
Output: 0 1 2 3
Explanation:
0 is connected to 1 , 3.
1 is connected to 2. 
2 is connected to 1.
3 is connected to 0. 
so starting from 0, it will go to 1 then 2
then back to 0 then 0 to 3
thus dfs will be 0 1 2 3. 

Your task:
You don’t need to read input or print anything. Your task is to complete the function dfsOfGraph() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns  a list containing the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)

Constraints:
1 ≤ V, E ≤ 104
*/

void dfs(int curr, vector<int> adj[], vector<int> &ans, vector<int> &visited)
{
  ans.push_back(curr);
  for (auto &n : adj[curr])
  {
    if (!visited[n])
    {
      visited[n] = 1;
      dfs(n, adj, ans, visited);
    }
  }
}

//Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
  vector<int> ans;
  vector<int> visited(V, 0);
  for (int i = 0; i < V; ++i)
  {
    if (!visited[i])
    {
      visited[i] = 1;
      dfs(i, adj, ans, visited);
    }
  }
  return ans;
}