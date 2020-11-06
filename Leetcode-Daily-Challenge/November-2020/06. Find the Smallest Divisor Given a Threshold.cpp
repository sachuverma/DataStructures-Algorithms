/*
Find the Smallest Divisor Given a Threshold
===========================================

Given an array of integers nums and an integer threshold, we will choose a positive integer divisor and divide all the array by it and sum the result of the division. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.


Example 1:
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 

Example 2:
Input: nums = [2,3,5,7,11], threshold = 11
Output: 3

Example 3:
Input: nums = [19], threshold = 5
Output: 4

Constraints:
1 <= nums.length <= 5 * 10^4
1 <= nums[i] <= 10^6
nums.length <= threshold <= 10^6

Hint #1  
Examine every possible number for solution. Choose the largest of them.

Hint #2  
Use binary search to reduce the time complexity.
*/

class Solution
{
  int calculate(vector<int> &arr, int divisor)
  {
    int ans = 0;
    for (auto &i : arr)
      ans += ceil((float)i / divisor);
    return ans;
  }

public:
  int smallestDivisor(vector<int> &nums, int threshold)
  {
    sort(nums.begin(), nums.end());
    int ans = INT_MAX;
    int i = 1, j = nums[nums.size() - 1];

    while (i <= j)
    {
      int mid = (i + j) / 2;
      if (calculate(nums, mid) <= threshold)
      {
        ans = min(ans, mid);
        j = mid - 1;
      }
      else
      {
        i = mid + 1;
      }
    }

    return ans;
  }
};
