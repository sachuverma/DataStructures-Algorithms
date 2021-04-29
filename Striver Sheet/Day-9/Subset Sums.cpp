/*
Subset Sums
===========

Given a list(Arr) of N integers, print sums of all subsets in it. Output should be printed in increasing order of sums.

Example 1:
Input:
N = 2
Arr = [2, 3]
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 

Sum = 2+3 = 5.
Example 2:
Input:
N = 3
Arr = [5, 2, 1]
Output:
0 1 2 3 5 6 7 8
Your Task:  
You don't need to read input or print anything. Your task is to complete the function subsetSum() which takes a list/vector and an integer N as an input parameter and return the list/vector of all the subset sums in increasing order.

Expected Time Complexity: O(2N)
Expected Auxiliary Space: O(2N)

Constraints:
1 <= N <= 15
0 <= Arr[i] <= 10000
*/

void dfs(vector<int> &arr, int i, vector<int> &ans, int stn)
{
  if (i == arr.size())
  {
    ans.push_back(stn);
    return;
  }

  dfs(arr, i + 1, ans, stn);
  dfs(arr, i + 1, ans, stn + arr[i]);
}

vector<int> subsetSums(vector<int> arr, int N)
{
  vector<int> ans;
  dfs(arr, 0, ans, 0);
  sort(ans.begin(), ans.end());
  return ans;
}
