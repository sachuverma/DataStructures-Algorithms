
void backtrack(int m[MAX][MAX], int visited[MAX][MAX], int n, int i, int j, vector<string> &ans, string curr = "")
{
  if (i < 0 || j < 0 || i >= n || j >= n || m[i][j] == 0 || visited[i][j] == 1)
    return;
  if (i == n - 1 && j == n - 1)
    ans.push_back(curr);

  visited[i][j] = 1;
  string s;
  s = curr + "D";
  backtrack(m, visited, n, i + 1, j, ans, s);
  s = curr + "L";
  backtrack(m, visited, n, i, j - 1, ans, s);
  s = curr + "R";
  backtrack(m, visited, n, i, j + 1, ans, s);
  s = curr + "U";
  backtrack(m, visited, n, i - 1, j, ans, s);
  visited[i][j] = 0;
}

vector<string> findPath(int m[MAX][MAX], int n)
{
  vector<string> ans;
  int visited[MAX][MAX] = {0};
  backtrack(m, visited, n, 0, 0, ans);
  return ans;
}