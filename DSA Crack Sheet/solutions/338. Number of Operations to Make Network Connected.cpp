
class Solution
{

  void dfs(int curr, unordered_map<int, vector<int>> &adj, vector<int> &visited)
  {
    for (auto &neighbor : adj[curr])
    {
      if (!visited[neighbor])
      {
        visited[neighbor] = 1;
        dfs(neighbor, adj, visited);
      }
    }
  }

  void bfs(int curr, unordered_map<int, vector<int>> &adj, vector<int> &visited)
  {
    queue<int> pending;
    pending.push(curr);
    while (pending.size())
    {
      int elem = pending.front();
      pending.pop();
      for (auto &i : adj[elem])
      {
        if (!visited[i])
        {
          visited[i] = 1;
          pending.push(i);
        }
      }
    }
  }

public:
  int makeConnected(int n, vector<vector<int>> &connections)
  {
    int N = connections.size(), components = 0;
    ;
    if (n > N + 1)
      return -1;

    unordered_map<int, vector<int>> adj;
    vector<int> visited(n, 0);

    for (auto &i : connections)
    {
      adj[i[0]].push_back(i[1]);
      adj[i[1]].push_back(i[0]);
    }

    for (int i = 0; i < n; ++i)
    {
      if (!visited[i])
      {
        visited[i] = 1;
        bfs(i, adj, visited);
        components++;
      }
    }

    return components == 0 ? 0 : components - 1;
  }
};
