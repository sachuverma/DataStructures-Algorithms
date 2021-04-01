/*
Bishu and Soldiers
==================

Bishu went to fight for Coding Club. There were N soldiers with various powers. There will be Q rounds to fight and in each round Bishu's power will be varied. With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). After each round, All the soldiers who are dead in previous round will reborn.Such that in each round there will be N soldiers to fight. As Bishu is weak in mathematics, help him to count the number of soldiers that he can kill in each round and total sum of their powers.

1<=N<=10000
1<=power of each soldier<=100
1<=Q<=10000
1<=power of bishu<=100

Sample Input
7
1 2 3 4 5 6 7
3
3
10
2
Sample Output
3 6
7 28
2 3

Time Limit: 1
Memory Limit: 256

Explanation:
In first round bhishu power is 3
So there are 3 soldiers whose power is <=3 and the sum of their power is 1+2+3=6
therefore ans= 3 6
same for the next round
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> powers(n, 0);
  for (auto &i : powers)
    cin >> i;
  sort(powers.begin(), powers.end());

  vector<int> sum(n, 0);
  sum[0] = powers[0];
  for (int i = 1; i < n; ++i)
    sum[i] = sum[i - 1] + powers[i];

  int t;
  cin >> t;
  while (t--)
  {
    int m;
    cin >> m;
    int ans = upper_bound(powers.begin(), powers.end(), m) - powers.begin();
    cout << ans << " " << sum[ans - 1] << endl;
  }
  return 0;
}
