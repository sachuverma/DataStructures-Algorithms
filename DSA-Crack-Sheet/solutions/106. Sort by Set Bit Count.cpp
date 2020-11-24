bool static comp(int a, int b)
{
  int c1 = 0, c2 = 0;
  while (a)
  {
    c1 += (a & 1);
    a = a >> 1;
  }
  while (b)
  {
    c2 += (b & 1);
    b = b >> 1;
  }

  if (c1 == c2)
    return a < b;
  return c1 > c2;
}

void sortBySetBitCount(int arr[], int n)
{
  stable_sort(arr, arr + n, comp);
}
