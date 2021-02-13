/*
Minimum number of jumps
=======================

Given an array of integers where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

Example 1:
Input:
N=11 
arr=1 3 5 8 9 2 6 7 6 8 9 
Output: 3 
Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to last. 

Example 2:
Input :
N= 6
arr= 1 4 3 2 6 7
Output: 2 
Explanation: 
First we jump from the 1st to 2nd element 
and then jump to the last element.

Your task:
You don't need to read input or print anything. Your task is to complete function minJumps() which takes the array arr and it's size N as input parameters and returns the minimum number of jumps.

Constraints:
1 ≤ N ≤ 107
0 <= ai <= 107
*/

// Function to return minimum number of jumps to end of array

int minJumps(int arr[], int n)
{
  if (n <= 1)
    return 0;
  if (arr[0] == 0)
    return -1;
  int maxReach = arr[0], step = arr[0];
  int jump = 1, i = 1;
  for (i = 1; i < n; ++i)
  {
    if (i == n - 1)
      return jump;
    maxReach = max(maxReach, i + arr[i]);
    step--;
    if (step == 0)
    {
      jump++;
      if (i >= maxReach)
        return -1;
      step = maxReach - i;
    }
  }
  return -1;
}
