
int mod = pow(10, 9) + 7;
long long calc(Node *l1)
{
  auto temp = l1;
  long long ans = 0;
  while (l1)
  {
    ans = ((ans % mod * 10 % mod) % mod + (l1->data) % mod) % mod;
    l1 = l1->next;
  }
  return ans;
}

long long multiplyTwoLists(Node *l1, Node *l2)
{
  long long n1 = calc(l1), n2 = calc(l2);
  long long ans = (n1 % mod * n2 % mod) % mod;
  return ans;
}
