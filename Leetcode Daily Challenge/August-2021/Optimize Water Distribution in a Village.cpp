/*
Optimize Water Distribution in a Village
========================================

There are n houses in a village. We want to supply water for all the houses by building wells and laying pipes.

For each house i, we can either build a well inside it directly with cost wells[i - 1] (note the -1 due to 0-indexing), or pipe in water from another well to it. The costs to lay pipes between houses are given by the array pipes, where each pipes[j] = [house1j, house2j, costj] represents the cost to connect house1j and house2j together using a pipe. Connections are bidirectional.

Return the minimum total cost to supply water to all houses.

Example 1:
Input: n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
Output: 3
Explanation: 
The image shows the costs of connecting houses using pipes.
The best strategy is to build a well in the first house with cost 1 and connect the other houses to it with cost 2 so the total cost is 3.
 
Constraints:
1 <= n <= 104
wells.length == n
0 <= wells[i] <= 105
1 <= pipes.length <= 104
pipes[j].length == 3
1 <= house1j, house2j <= n
0 <= costj <= 105
house1j != house2j
*/

class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent = vector <int> (n+1, 0);
        rank = vector <int> (n+1, 0);
        
        for(int i = 0; i <= n; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int a) {
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    
    void join(int a, int b) {
        int pa = find(a), pb = find(b);
        if(pa == pb) return;
        
        if(rank[pa] > rank[pb]) parent[pb] = pa;
        else if(rank[pa] < rank[pb]) parent[pa] = pb;
        else {
            parent[pa] = pb;
            rank[pb]++;
        }
    }
};

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        DSU obj(n);
        vector<vector<int>> edges;
        
        for(auto& pipe : pipes) edges.push_back({ pipe[2], pipe[0], pipe[1] });
        for(int i = 0; i < n; ++i) edges.push_back({ wells[i], 0, i+1 });
        
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
           return a[0] < b[0]; 
        });
        
        int edges_added = 0;
        int ans = 0;
        
        for(int i = 0; i < edges.size() && edges_added < n; ++i) {
            int cost = edges[i][0], node1 = edges[i][1], node2 = edges[i][2];
            if(obj.find(node1) == obj.find(node2)) continue;
            
            obj.join(node1, node2);
            ans += cost;
            edges_added++;
        }
        
        return ans;
    }
};