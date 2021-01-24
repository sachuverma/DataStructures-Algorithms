
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
  vector<bool> visited(V, false);
  vector<int> ans;
  queue<int> pending;
  pending.push(0);
  while (pending.size())
  {
    int fr = pending.front();
    pending.pop();
    if (!visited[fr])
    {
      ans.push_back(fr);
      visited[fr] = true;
    }
    for (auto i : adj[fr])
    {
      if (!visited[i])
        pending.push(i);
    }
  }
  return ans;
}
