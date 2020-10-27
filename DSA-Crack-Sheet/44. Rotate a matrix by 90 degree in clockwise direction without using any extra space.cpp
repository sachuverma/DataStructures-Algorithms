// O(n2);
#include <bits/stdc++.h>
using namespace std;

void rotate90Clockwise(vector<vector<int>> mat)
{
  int N = mat.size();
  for (int i = 0; i < N; ++i)
    for (int j = i; j < N; ++j)
      swap(mat[i][j], mat[j][i]);

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N / 2; ++j)
      swap(mat[i][j], mat[i][N - j - 1]);

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
      cout << mat[i][j] << " ";
    cout << endl;
  }
}

int main()
{
  int N;
  cin >> N;
  vector<vector<int>> mat(N, vector<int>(N, 0));
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      cin >> mat[i][j];

  rotate90Clockwise(mat);
  return 0;
}
