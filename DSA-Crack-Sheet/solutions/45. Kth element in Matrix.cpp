
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  int i, j;

  for (i = 0; i < n; i++)
  {
    pq.push(make_pair(mat[0][i], make_pair(0, i)));
  }

  for (i = 0; i < k - 1; i++)
  {
    auto x = pq.top();
    pq.pop();
    if (x.second.first < n - 1)
    {
      pq.push(make_pair(mat[x.second.first + 1][x.second.second], make_pair(x.second.first + 1, x.second.second)));
    }
  }
  return pq.top().first;
}
