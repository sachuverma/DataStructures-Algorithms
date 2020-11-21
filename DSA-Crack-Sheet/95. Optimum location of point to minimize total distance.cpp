#include <bits/stdc++.h>
using namespace std;

double distance(double &x, double &y, pair<int, int> &p)
{
  return sqrt(pow(x - p.first, 2) + pow(y - p.second, 2));
}

double compute(vector<pair<int, int>> &points, vector<int> &line, double X)
{
  double ans = 0;
  double Y = -1 * (line[2] + line[0] * X) / line[1];
  for (auto point : points)
    ans += distance(X, Y, point);
  return ans;
}

double findOptimumCost(vector<pair<int, int>> &points, vector<int> &line)
{
  double low = -1e6, high = 1e6;
  while ((high - low) > 1e-6)
  {
    double mid1 = low + (high - low) / 3;
    double mid2 = high - (high - low) / 3;

    double dist1 = compute(points, line, mid1);
    double dist2 = compute(points, line, mid2);

    if (dist1 < dist2)
      high = mid2;
    else
      low = mid1;
  }
  return compute(points, line, (low + high) / 2);
}

int main()
{
  vector<int> line(3);
  vector<pair<int, int>> points(5);

  for (auto &i : line)
    cin >> i;
  for (auto &i : points)
    cin >> i.first >> i.second;

  cout << findOptimumCost(points, line) << endl;

  return 0;
}
