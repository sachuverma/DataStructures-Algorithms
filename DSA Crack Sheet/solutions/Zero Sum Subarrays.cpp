/*
Zero Sum Subarrays
==================

You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

Example 1:
Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

Example 2:
Input:
n = 10
arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4]
[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

Your Task:
You don't need to read input or print anything. Complete the function findSubarray() that takes the array arr and its size n as input parameters and returns the total number of sub-arrays with 0 sum. 

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:    
1<= n <= 107
-1010 <= arri <= 1010
*/

//User function template for C++

// arr : given array
// n : size of the given array
ll findSubarray(vector<ll> arr, int n)
{
  unordered_map<int, vector<int>> sums;
  ll sum = 0;
  ll ans = 0;
  for (int i = 0; i < n; ++i)
  {
    sum += arr[i];
    if (sum == 0)
      ans++;
    if (sums.find(sum) != sums.end())
      ans += sums[sum].size();
    sums[sum].push_back(i);
  }
  return ans;
}
