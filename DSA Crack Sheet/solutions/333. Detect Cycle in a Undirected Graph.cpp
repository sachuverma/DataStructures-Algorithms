
bool isCyclicUtil(int v, vector<int> adj[], vector<bool> &visited, int parent)
{
  visited[v] = true;
  for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
  {
    if (!visited[*i])
    {
      if (isCyclicUtil(*i, adj, visited, v))
        return true;
    }
    else if (*i != parent)
      return true;
  }
  return false;
}

bool isCycle(int V, vector<int> adj[])
{
  vector<bool> visited(V, false);
  for (int i = 0; i < V; i++)
    visited[i] = false;
  for (int u = 0; u < V; u++)
  {
    if (!visited[u])
      if (isCyclicUtil(u, adj, visited, -1))
        return true;
  }
  return false;
}
