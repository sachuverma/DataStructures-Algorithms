
class Solution
{
public:
  string countAndSay(int n)
  {
    if (n == 1)
      return "1";

    string prev = countAndSay(n - 1);
    string ans = "";

    int count = 1;
    for (int i = 0; i < prev.length(); ++i)
    {
      if (i == prev.length() - 1)
      {
        ans += to_string(count);
        ans += prev[i];
      }
      else if (prev[i] == prev[i + 1])
        count = count + 1;
      else
      {
        ans += to_string(count);
        ans += prev[i];
        count = 1;
      }
    }

    return ans;
  }
};
