
bool isInside(int x, int y, int N)
{
  if (x >= 1 && x <= N && y >= 1 && y <= N)
    return true;
  return false;
}

int minStepToReachTarget(vector<int> &knightPos, vector<int> &targetPos, int N)
{
  int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
  int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

  queue<vector<int>> q;
  q.push({knightPos[0], knightPos[1], 0});

  bool visit[N + 1][N + 1];

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      visit[i][j] = false;

  visit[knightPos[0]][knightPos[1]] = true;

  while (!q.empty())
  {
    auto t = q.front();
    q.pop();
    if (t[0] == targetPos[0] && t[1] == targetPos[1])
      return t[2];

    for (int i = 0; i < 8; i++)
    {
      int x = t[0] + dx[i];
      int y = t[1] + dy[i];

      if (isInside(x, y, N) && !visit[x][y])
      {
        visit[x][y] = true;
        q.push({x, y, t[2] + 1});
      }
    }
  }
}