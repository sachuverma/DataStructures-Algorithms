/*
AGGRCOW - Aggressive cows
=========================

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.

Example
Input:
1
5 3
1
2
8
4
9
Output:
3

Output details:
FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool canKeep(vector<ll> &stalls, ll &n, ll &cows, ll &gap)
{
  ll count = 1;
  ll last_cow = stalls[0];

  for (auto i = 1; i < n; ++i)
  {
    if (stalls[i] - last_cow >= gap)
    {
      last_cow = stalls[i];
      count++;
      if (count == cows)
        return true;
    }
  }

  return false;
}

void solve()
{
  ll n, c;
  cin >> n >> c;
  vector<ll> stalls(n, 0);
  for (auto &i : stalls)
    cin >> i;
  sort(stalls.begin(), stalls.end());

  ll s = 1, e = stalls[n - 1] - stalls[0];
  int ans = 0;
  while (s <= e)
  {
    ll mid = (e + s) / 2;
    if (canKeep(stalls, n, c, mid))
    {
      ans = mid;
      s = mid + 1;
    }
    else
      e = mid - 1;
  }

  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  cin >> t;

  while (t--)
  {
    solve();
  }

  return 0;
}
