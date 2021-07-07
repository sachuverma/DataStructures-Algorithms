/*
Partition Equal Subset Sum
==========================

Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:
Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.

Example 2:
Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.

Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)

Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
*/

bool dfs(int arr[], int i, int N, int sum, vector<vector<int>> &memo)
{
  if (sum == 0)
    return true;
  if (i == N)
    return false;

  if (memo[i][sum] != -1)
    return memo[i][sum];

  if (arr[i] > sum)
    return memo[i][sum] = dfs(arr, i + 1, N, sum, memo);

  return memo[i][sum] = dfs(arr, i + 1, N, sum, memo) || dfs(arr, i + 1, N, sum - arr[i], memo);
}

int equalPartition(int N, int arr[])
{
  int sum = 0;
  for (int i = 0; i < N; ++i)
    sum += arr[i];
  if (sum % 2 != 0)
    return false;

  vector<vector<int>> memo(N + 1, vector<int>(sum + 1, -1));
  return dfs(arr, 0, N, sum / 2, memo);
}