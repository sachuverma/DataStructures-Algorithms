#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    unordered_set<int> s;
    int no, n1, n2;
    cin >> n1 >> n2;

    for (int i = 0; i < n1 + n2; ++i)
    {
      cin >> no;
      s.insert(no);
    }

    cout << s.size() << endl;
  }
  return 0;
}
