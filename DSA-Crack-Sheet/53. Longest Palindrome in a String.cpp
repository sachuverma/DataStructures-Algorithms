
#include <bits/stdc++.h>
using namespace std;

string LPS(string s)
{
  int n = s.size();
  if (n <= 1)
    return s;

  string ans = "";
  int max_length = 0;
  vector<vector<int>> dp(n, vector<int>(n, -1));

  for (int i = 0; i < n; ++i)
    dp[i][i] = 1;
  ans = s.substr(0, 1);
  max_length = 1;

  for (int i = 0; i + 1 < n; ++i)
  {
    if (s[i] == s[i + 1])
    {
      dp[i][i + 1] = 1;
      if (max_length < 2)
      {
        max_length = 2;
        ans = s.substr(i, 2);
      }
    }
    else
      dp[i][i + 1] = 0;
  }

  for (int gap = 2; gap < n; ++gap)
  {
    for (int i = 0; i + gap < n; ++i)
    {
      int j = i + gap;
      if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
      {
        dp[i][j] = 1;
        if (max_length < j - i + 1)
        {
          max_length = j - i + 1;
          ans = s.substr(i, j - i + 1);
        }
      }
      else
        dp[i][j] = 0;
    }
  }
  return ans;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    cout << LPS(s) << endl;
  }
  return 0;
}
