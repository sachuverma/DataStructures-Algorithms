
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int arr[] = {-1000, 154451, 54445, 54541, 35430, 354000};
  int arr_size = 6;

  int Min = INT_MAX, Max = INT_MIN;
  for (int i = 0; i < arr_size; ++i)
  {
    Min = min(Min, arr[i]);
    Max = max(Max, arr[i]);
  }

  cout << "Minimum element is " << Min << endl;
  cout << "Maximum element is " << Max;

  return 0;
}

/* =================================================================== */
/* This algo does 3n/2 -2 comparisons if n is a power of 2. 
And it does more than 3n/2 -2 comparisons if n is not a power of 2 */

#include <bits/stdc++.h>
using namespace std;

pair<int, int> getMinMax(vector<int> arr, int s, int e)
{
  int size = e - s + 1, mid = (s + e) / 2;
  if (size == 0)
    return {INT_MAX, INT_MIN};
  if (size == 1)
    return {arr[0], arr[0]};
  if (size == 2)
    return {min(arr[0], arr[1]), max(arr[0], arr[1])};

  pair<int, int> left = getMinMax(arr, s, mid);
  pair<int, int> right = getMinMax(arr, mid + 1, e);

  return {min(left.first, right.first), max(left.second, right.second)};
}

int main()
{
  vector<int> arr = {-1000, 154451, 54445, 54541, 35430, 354000};
  int Min = INT_MAX, Max = INT_MIN;

  auto Ans = getMinMax(arr, 0, arr.size());
  Min = Ans.first;
  Max = Ans.second;

  cout << "Minimum element is " << Min << endl;
  cout << "Maximum element is " << Max;

  return 0;
}
