// using STL
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    do
    {
      cout << s << " ";
    } while (next_permutation(s.begin(), s.end()));
    cout << endl;
  }
  return 0;
}

/* =================================== */
#include <bits/stdc++.h>
using namespace std;

void print(string a, int l, int r)
{
  if (l == r)
    cout << a << " ";
  else
  {
    for (int i = l; i <= r; i++)
    {
      swap(a[l], a[i]);
      print(a, l + 1, r);
      swap(a[l], a[i]);
    }
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    print(s, 0, s.size() - 1);
    cout << endl;
  }
  return 0;
}
