
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
  int n = image.size(), m = image[0].size();
  vector<vector<int>> visited(n, vector<int>(m, 0));
  int oldColor = image[sr][sc];

  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  queue<vector<int>> pending;
  pending.push({sr, sc});
  visited[sr][sc] = 1;

  while (pending.size())
  {
    auto curr = pending.front();
    pending.pop();
    int x = curr[0], y = curr[1];
    image[x][y] = newColor;
    visited[x][y] = 1;

    for (int i = 0; i < 4; ++i)
    {
      int nextX = x + dx[i];
      int nextY = y + dy[i];
      if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < m && !visited[nextX][nextY] && image[nextX][nextY] == oldColor)
      {
        visited[nextX][nextY] = 1;
        pending.push({nextX, nextY});
      }
    }
  }

  return image;
}
