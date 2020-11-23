
int median(vector<vector<int>> &m, int r, int c)
{
  int min = INT_MAX, max = INT_MIN;
  for (int i = 0; i < r; i++)
  {
    if (m[i][0] < min)
      min = m[i][0];

    if (m[i][c - 1] > max)
      max = m[i][c - 1];
  }

  int desired = (r * c + 1) / 2;
  while (min < max)
  {
    int mid = min + (max - min) / 2;
    int place = 0;

    for (int i = 0; i < r; ++i)
      place += upper_bound(m[i].begin(), m[i].end(), mid) - m[i].begin();
    if (place < desired)
      min = mid + 1;
    else
      max = mid;
  }
  return min;
}
