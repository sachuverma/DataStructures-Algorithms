// O(n4)

#include <bits/stdc++.h>
using namespace std;

int findMaxValue(int mat[5][5])
{
  int N = 5, maxValue = INT_MIN;
  for (int a = 0; a < N - 1; a++)
    for (int b = 0; b < N - 1; b++)
      for (int d = a + 1; d < N; d++)
        for (int e = b + 1; e < N; e++)
          if (maxValue < (mat[d][e] - mat[a][b]))
            maxValue = mat[d][e] - mat[a][b];

  return maxValue;
}

int main()
{
  int mat[5][5] = {
      {1, 2, -1, -4, -20},
      {-8, -3, 4, 2, 1},
      {3, 8, 6, 1, 3},
      {-4, -1, 1, 7, -6},
      {0, -4, 10, -5, 1}};

  cout << findMaxValue(mat);
  return 0;
}

/* ============================== */
// O(n2)

#include <bits/stdc++.h>
using namespace std;

int findMaxValue(vector<vector<int>> mat)
{
  int N = mat.size();
  vector<vector<int>> maxArr(N, vector<int>(N, 0));

  int maxValue = INT_MIN;
  maxArr[N - 1][N - 1] = mat[N - 1][N - 1];

  int maxv = mat[N - 1][N - 1];
  for (int j = N - 2; j >= 0; j--)
  {
    if (mat[N - 1][j] > maxv)
      maxv = mat[N - 1][j];
    maxArr[N - 1][j] = maxv;
  }

  maxv = mat[N - 1][N - 1];
  for (int i = N - 2; i >= 0; i--)
  {
    if (mat[i][N - 1] > maxv)
      maxv = mat[i][N - 1];
    maxArr[i][N - 1] = maxv;
  }

  for (int i = N - 2; i >= 0; i--)
  {
    for (int j = N - 2; j >= 0; j--)
    {

      if (maxArr[i + 1][j + 1] - mat[i][j] > maxValue)
        maxValue = maxArr[i + 1][j + 1] - mat[i][j];
      maxArr[i][j] = max(mat[i][j], max(maxArr[i][j + 1], maxArr[i + 1][j]));
    }
  }
  return maxValue;
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

  cout << findMaxValue(mat);
  return 0;
}
