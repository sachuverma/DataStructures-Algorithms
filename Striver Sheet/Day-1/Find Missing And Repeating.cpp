/*
Find Missing And Repeating
==========================

Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:
Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.

Example 2:
Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer ( The first index contains B and second index contains A.)

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ N
*/

class Solution
{
public:
  int *findTwoElement(int *arr, int n)
  {
    int XOR = 0;
    for (int i = 0; i < n; ++i)
      XOR ^= ((i + 1) ^ arr[i]);

    int setbit_no = XOR & ~(XOR - 1);
    int bucket1 = 0, bucket2 = 0;

    for (int i = 0; i < n; ++i)
    {
      if ((arr[i] & setbit_no))
        bucket1 ^= arr[i];
      else
        bucket2 ^= arr[i];

      if (((i + 1) & setbit_no))
        bucket1 ^= (i + 1);
      else
        bucket2 ^= (i + 1);
    }

    int *ans = new int[2];

    int flag = 0;
    for (int i = 0; i < n; ++i)
    {
      if (arr[i] == bucket1)
      {
        flag = 1;
        break;
      }
    }

    if (flag)
    {
      ans[0] = bucket1;
      ans[1] = bucket2;
    }
    else
    {
      ans[1] = bucket1;
      ans[0] = bucket2;
    }
    return ans;
  }
};
