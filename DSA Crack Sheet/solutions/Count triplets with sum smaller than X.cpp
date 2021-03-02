/*
Count triplets with sum smaller than X
======================================

Given an array arr[] of distinct integers of size N and a sum value X, the task is to find count of triplets with the sum smaller than the given sum value X.

Example 1:
Input: N = 6, X = 2
arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with 
sum less than 2 (-2, 0, 1) and (-2, 0, 3). 

Example 2:
Input: N = 5, X = 12
arr[] = {5, 1, 3, 4, 7}
Output: 4
Explanation: Below are triplets with 
sum less than 12 (1, 3, 4), (1, 3, 5), 
(1, 3, 7) and (1, 4, 5).

Your Task:
This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function countTriplets() that take array arr[], integer N  and integer X as parameters and returns the count of triplets.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(1).

Constraints:
3 ≤ N ≤ 103
*/

long long countTriplets(long long arr[], int n, long long sum)
{
  sort(arr, arr + n);
  long long count = 0;
  for (int i = 0; i < n; ++i)
  {
    int j = i + 1, k = n - 1;
    while (j < k)
    {
      if (arr[i] + arr[j] + arr[k] < sum)
      {
        count += (k - j);
        j++;
      }
      else
        k--;
    }
  }
  return count;
}
