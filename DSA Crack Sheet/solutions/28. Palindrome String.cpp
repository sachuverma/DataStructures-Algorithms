
class Solution
{
public:
  int isPlaindrome(string S)
  {
    int front = 0, back = S.size() - 1;
    while (front < back)
      if (S[front++] != S[back--])
        return 0;
    return 1;
  }
};
