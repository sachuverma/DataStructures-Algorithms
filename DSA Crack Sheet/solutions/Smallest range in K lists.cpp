/*
Smallest range in K lists
=========================

Given K sorted lists of integers of size N each, find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, find the first such range found.

Example 1:
Input:
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
Output: 1 2
Explanation: K = 3
A:[1 3 5 7 9]
B:[0 2 4 6 8]
C:[2 3 5 7 11]
Smallest range is formed by number 1
present in first list and 2 is present
in both 2nd and 3rd list.

Example 2:
Input:
N = 4, K = 3
KSortedArray[][] = {{1 2 3 4},
                    {5 6 7 8},
                    {9 10 11 12}}
Output: 4 9

Your Task :
Complete the function findSmallestRange() that receives array , array size n and k as parameters and returns the output range (as a pair in cpp and array of size 2 in java and python)

Expected Time Complexity : O(n * k *log k)
Expected Auxilliary Space  : O(k)

Constraints:
1 <= K,N <= 500
*/

pair<int, int> findSmallestRange(int arr[][N], int n, int k)
{
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
  int Min = INT_MAX, Max = INT_MIN;
  int range = INT_MAX;

  for (int i = 0; i < k; ++i)
  {
    Max = max(Max, arr[i][0]);
    pq.push({arr[i][0], i, 0});
  }

  int temp_max = Max, temp_min = -1;

  while (pq.size())
  {
    auto curr = pq.top();
    pq.pop();

    temp_min = curr[0];
    int curr_row = curr[1], curr_col = curr[2];

    if (range > temp_max - temp_min + 1)
    {
      Min = temp_min;
      Max = temp_max;
      range = Max - Min + 1;
    }

    if (curr_col + 1 < n)
    {
      pq.push({arr[curr_row][curr_col + 1], curr_row, curr_col + 1});
      temp_max = max(temp_max, arr[curr_row][curr_col + 1]);
    }
    else
      break;
  }

  return {Min, Max};
}