
void dfs(int V, vector<int> adj[], vector<int> &ans, unordered_set<int> &visited)
{
  if (visited.find(V) != visited.end())
    return;

  visited.insert(V);
  ans.push_back(V);

  for (auto &i : adj[V])
    dfs(i, adj, ans, visited);
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
  vector<int> ans;
  unordered_set<int> visited;
  dfs(0, adj, ans, visited);
  return ans;
}