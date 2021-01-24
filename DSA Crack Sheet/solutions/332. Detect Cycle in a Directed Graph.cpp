
bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack, vector<int> adj[])
{
  if (visited[v] == false)
  {
    visited[v] = true;
    recStack[v] = true;
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
    {
      if (!visited[*i] && isCyclicUtil(*i, visited, recStack, adj))
        return true;
      else if (recStack[*i])
        return true;
    }
  }
  recStack[v] = false;
  return false;
}

bool isCyclic(int V, vector<int> adj[])
{
  vector<bool> visited(V, false), recStack(V, false);
  for (int i = 0; i < V; i++)
  {
    visited[i] = false;
    recStack[i] = false;
  }

  for (int i = 0; i < V; i++)
    if (isCyclicUtil(i, visited, recStack, adj))
      return true;

  return false;
}
