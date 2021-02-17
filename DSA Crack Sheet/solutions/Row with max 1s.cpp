/*
Row with max 1s
===============

Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:
Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).

Example 2:
Input: 
N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1
Explanation: Row 1 contains 2 1's (0-based
indexing).

Your Task:  
You don't need to read input or print anything. Your task is to complete the function rowWithMax1s() which takes the array of booleans arr[][], n and m as input parameters and returns the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N, M ≤ 103
0 ≤ Arr[i][j] ≤ 1 
*/

int rowWithMax1s(vector<vector<int>> arr, int R, int C)
{
  int max_row_index = -1;
  int j = upper_bound(arr[0].begin(), arr[0].end(), 0) - arr[0].begin();
  if (j == 0)
    return 0;

  for (int i = 1; i < R; i++)
  {
    while (j - 1 >= 0 && arr[i][j - 1] == 1)
    {
      j = j - 1;
      max_row_index = i;
    }
  }
  return max_row_index;
}
