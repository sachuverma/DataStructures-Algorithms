/*
Partition array to K subsets
============================

Given an integer array a[ ] of N elements and an integer K, the task is to check if the array a[ ] could be divided into K non-empty subsets with equal sum of elements.
Note: All elements of this array should be part of exactly one partition.

Example 1:
Input: 
N = 5
a[] = {2,1,4,5,6}
K = 3
Output: 
1
Explanation: we can divide above array 
into 3 parts with equal sum as (2, 4), 
(1, 5), (6)

Example 2:
Input: 
N = 5 
a[] = {2,1,5,5,6}
K = 3
Output: 
0
Explanation: It is not possible to divide
above array into 3 parts with equal sum.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isKPartitionPossible() which takes the array a[], the size of the array N, and the value of K as inputs and returns true(same as 1) if possible, otherwise false(same as 0).

Expected Time Complexity: O(N*2N).
Expected Auxiliary Space: O(2N).

Constraints:
1 ≤ K ≤ N ≤ 10
1 ≤ a[i] ≤ 100
*/

bool dfs(int a[], int j, int k, int n, int vis[], int t, int c)
{
  if (c > t)
    return false;
  if (j == k)
    return true;
  if (c == t)
  {
    return dfs(a, j + 1, k, n, vis, t, 0);
  }

  for (int l = 0; l < n; ++l)
  {
    if (!vis[l])
    {
      vis[l] = 1;
      if (dfs(a, j, k, n, vis, t, c + a[l]))
        return true;
      vis[l] = 0;
    }
  }
  return false;
}

bool isKPartitionPossible(int a[], int n, int k)
{
  int sum = 0;
  for (int i = 0; i < n; ++i)
    sum += a[i];
  if (sum % k != 0)
    return false;
  int target = sum / k;
  int vis[n] = {0};

  return dfs(a, 0, k, n, vis, target, 0);
}