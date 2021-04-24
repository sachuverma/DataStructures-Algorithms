/*
Largest subarray with 0 sum
===========================

Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:
Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 104
-1000 <= A[i] <= 1000, for each valid i
*/

int maxLen(int A[], int n)
{
  vector<int> prefix(n, 0);
  prefix[0] = A[0];
  for (int i = 1; i < n; ++i)
    prefix[i] = prefix[i - 1] + A[i];

  unordered_map<int, int> m;
  int ans = 0;
  for (int i = 0; i < n; ++i)
  {
    if (prefix[i] == 0)
      ans = max(ans, i + 1);
    if (m.find(prefix[i]) != m.end())
    {
      ans = max(ans, i - m[prefix[i]]);
    }
    else
      m[prefix[i]] = i;
  }

  return ans;
}
