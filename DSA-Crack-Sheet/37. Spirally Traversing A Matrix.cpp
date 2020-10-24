
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));

    for (auto &row : mat)
      for (auto &el : row)
        cin >> el;

    int rs = 0, cs = 0, re = n - 1, ce = m - 1;
    int count = n * m;
    int i = 0, j = 0;

    while (count > 0)
    {
      // top
      for (int i = rs, j = cs; j <= ce && count > 0; ++j)
      {
        cout << mat[i][j] << " ";
        count--;
      }
      rs++;

      // right
      for (int i = rs, j = ce; i <= re && count > 0; ++i)
      {
        cout << mat[i][j] << " ";
        count--;
      }
      ce--;

      // bottom
      for (int i = re, j = ce; j >= cs && count > 0; --j)
      {
        cout << mat[i][j] << " ";
        count--;
      }
      re--;

      // left
      for (int i = re, j = cs; i >= rs && count > 0; --i)
      {
        cout << mat[i][j] << " ";
        count--;
      }
      cs++;
    }
    cout << endl;
  }
  return 0;
}
