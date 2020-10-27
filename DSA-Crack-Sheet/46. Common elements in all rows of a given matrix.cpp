
#include <bits/stdc++.h>
using namespace std;

void commonElement(vector<vector<int>> mat)
{
  int N = mat.size();
  unordered_map<int, int> mp;

  for (int j = 0; j < N; j++)
    mp[mat[0][j]] = 1;
  for (int i = 1; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (mp[mat[i][j]] == i)
      {
        mp[mat[i][j]] = i + 1;
        if (i == N - 1)
          cout << mat[i][j] << " ";
      }
    }
  }
}

int main()
{
  int N;
  cin >> N;
  vector<vector<int>> mat(N, vector<int>(N, 0));
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
      cin >> mat[i][j];
  }

  commonElement(mat);
  return 0;
}
