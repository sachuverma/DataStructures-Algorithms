/*
Count of Smaller Numbers After Self
===================================

You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example 1:
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Example 2:
Input: nums = [-1]
Output: [0]

Example 3:
Input: nums = [-1,-1]
Output: [0,0]

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

class Solution
{
public:
  vector<pair<int, int>> temp, B;

  void crossInversion(int st, int en, vector<int> &A)
  {
    int mid = (st + en) / 2;
    int i = st, j = mid + 1;
    int k = st;

    while (i <= mid && j <= en)
    {
      if (B[i].first <= B[j].first)
      {
        temp[k] = B[j];
        j++;
        k++;
      }
      else
      {
        temp[k] = B[i];
        A[B[i].second] += (en - j + 1);
        i++;
        k++;
      }
    }

    while (i <= mid)
    {
      temp[k] = B[i];
      A[B[i].second] += (en - j + 1);
      i++;
      k++;
    }

    while (j <= en)
    {
      temp[k] = B[j];
      j++;
      k++;
    }

    for (int i = st; i <= en; ++i)
      B[i] = temp[i];
  }

  void countInversion(int st, int en, vector<int> &A)
  {
    if (st >= en)
      return;
    int mid = (st + en) / 2;

    countInversion(st, mid, A);
    countInversion(mid + 1, en, A);
    crossInversion(st, en, A);
  }

  vector<int> countSmaller(vector<int> &A)
  {
    int n = A.size();

    temp = vector<pair<int, int>>(n, {0, 0});
    B = vector<pair<int, int>>(n, {0, 0});
    vector<int> ans(n, 0);

    for (int i = 0; i < n; ++i)
      B[i] = {A[i], i};

    countInversion(0, n - 1, ans);
    return ans;
  }
};