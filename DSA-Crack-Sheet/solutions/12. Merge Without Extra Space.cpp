//O(n*m)
void merge(int ar1[], int ar2[], int m, int n)
{
  for (int i = n - 1; i >= 0; i--)
  {
    int j, last = ar1[m - 1];
    for (j = m - 2; j >= 0 && ar1[j] > ar2[i]; j--)
      ar1[j + 1] = ar1[j];

    if (j != m - 2 || last > ar2[i])
    {
      ar1[j + 1] = ar2[i];
      ar2[i] = last;
    }
  }
}

/* ================================================= */
//O(m*nlog(n))
void merge(int arr1[], int arr2[], int m, int n)
{
  int i = 0, j = 0;
  while (i < m)
  {
    if (arr1[i] < arr2[j])
      i++;
    else
    {
      swap(arr1[i], arr2[j]);
      sort(arr2, arr2 + n);
      i++;
    }
  }
}

/* ================================================= */
// O((n+m)log(n+m))
int nextGap(int gap)
{
  if (gap <= 1)
    return 0;
  return (gap / 2) + (gap % 2);
}

void merge(int arr1[], int arr2[], int n, int m)
{
  int i, j, gap = n + m;
  for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
  {

    for (i = 0; i + gap < n; i++)
      if (arr1[i] > arr1[i + gap])
        swap(arr1[i], arr1[i + gap]);

    for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
      if (arr1[i] > arr2[j])
        swap(arr1[i], arr2[j]);

    if (j < m)
      for (j = 0; j + gap < m; j++)
        if (arr2[j] > arr2[j + gap])
          swap(arr2[j], arr2[j + gap]);
  }
}
