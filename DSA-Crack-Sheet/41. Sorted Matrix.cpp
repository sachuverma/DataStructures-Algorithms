
#include <bits/stdc++.h>
using namespace std;

void printMat(vector<vector<int>> mat)
{
  int n = mat.size();
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

  for (int i = 0; i < n; ++i)
    pq.push({mat[i][0], {i, 0}});
  while (pq.size())
  {
    int ele = pq.top().first;
    int row = pq.top().second.first;
    int col = pq.top().second.second;
    pq.pop();

    cout << ele << " ";
    if (col < n - 1)
      pq.push({mat[row][col + 1], {row, col + 1}});
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
        cin >> mat[i][j];
    }

    printMat(mat);
    cout << endl;
  }
  return 0;
}
