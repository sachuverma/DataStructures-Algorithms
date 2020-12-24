

bool compare(const Job &a, const Job &b)
{
  return a.profit > b.profit;
}

pair<int, int> JobScheduling(Job arr[], int n)
{
  sort(arr, arr + n, compare);
  int count = 0, profit = 0;

  bool slot[n] = {false};
  int result[n];

  for (int i = 0; i < n; i++)
    for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
      if (slot[j] == false)
      {
        result[j] = i;
        slot[j] = true;
        break;
      }

  for (int i = 0; i < n; i++)
    if (slot[i])
    {
      count++;
      profit += arr[result[i]].profit;
    }

  return {count, profit};
}
