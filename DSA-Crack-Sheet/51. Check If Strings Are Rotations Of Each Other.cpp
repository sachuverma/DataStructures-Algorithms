
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);

  string temp = s1 + s1;
  if (temp.find(s2) == string::npos)
    cout << "Not Rotation";
  else
    cout << "Rotation";

  return 0;
}
