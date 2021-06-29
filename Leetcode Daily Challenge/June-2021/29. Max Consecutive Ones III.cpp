/*
Max Consecutive Ones III
========================

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length

Hint #1  
One thing's for sure, we will only flip a zero if it extends an existing window of 1s. Otherwise, there's no point in doing it, right? Think Sliding Window!

Hint #2  
Since we know this problem can be solved using the sliding window construct, we might as well focus in that direction for hints. Basically, in a given window, we can never have > K zeros, right?

Hint #3  
We don't have a fixed size window in this case. The window size can grow and shrink depending upon the number of zeros we have (we don't actually have to flip the zeros here!).

Hint #4  
The way to shrink or expand a window would be based on the number of zeros that can still be flipped and so on.
*/

class Solution
{
public:
  int longestOnes(vector<int> &A, int k)
  {
    int ans = 0, i = 0, j = 0;

    while (j < A.size())
    {
      if (A[j] == 0)
        k--;
      while (k < 0 && A[i] == 1)
        i++;
      i++;
      k++;
      j++;
      ans = max(ans, j - i);
    }

    return ans;
  }
};