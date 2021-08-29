/*
Graph Valid Tree
==================

You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.

Example 1:
Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true

Example 2:
Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false
 
Constraints:
1 <= 2000 <= n
0 <= edges.length <= 5000
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no self-loops or repeated edges.
*/

class Solution {
public:
    void dfs(int curr, vector<vector<int>>& adj, vector<int>& vis, int& count) {
        count++;
        for(int child: adj[curr]) {
            if(vis[child] == 0) {
                vis[child] = 1;
                dfs(child, adj, vis, count);
            }
        }
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        if(m != n-1) return false;
        
        vector<vector<int>> adj(n, vector<int>(0));
        
        for(auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int count = 0;
        vector<int> vis(n);
        vis[0] = 1;
        
        dfs(0, adj, vis, count);
        return count == n;
    }
};