
#include <bits/stdc++.h>
using namespace std;

bool shuffle(string s1, string s2, string pattern)
{
  if (s1.size() + s2.size() != pattern.size())
    return false;

  int i = 0, j = 0, k = 0;
  while (k < pattern.size())
  {
    if (i < s1.size() && pattern[k] == s1[i])
    {
      i++;
      k++;
    }
    else if (j < s2.size() && pattern[k] == s2[j])
    {
      j++;
      k++;
    }
    else
      return false;
  }

  return true;
}

int main()
{
  string s1 = "abc", s2 = "def";
  vector<string> patterns = {"abcdef", "ahbefc", "afbedc", "adibfc"};

  for (auto s : patterns)
  {
    if (shuffle(s1, s2, s))
      cout << "Shuffle\n";
    else
      cout << "Not Shuffle\n";
  }

  return 0;
}
