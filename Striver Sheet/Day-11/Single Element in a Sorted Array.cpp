/*
Single Element in a Sorted Array
================================

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

class Solution
{
public:
  int singleNonDuplicate(vector<int> &nums)
  {
    int i = 0, j = nums.size() - 1;
    int n = nums.size();

    if (j == 0)
      return nums[j];
    else if (nums[0] != nums[1])
      return nums[0];
    else if (nums[n - 2] != nums[n - 1])
      return nums[n - 1];

    while (i <= j)
    {
      int mid = j - (j - i) / 2;
      if (mid > 0 && mid < n - 1)
      {
        if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid])
          return nums[mid];

        // agr pichla same hai or
        // pichla index even hai toh right me milega nhi toh left m
        if (nums[mid - 1] == nums[mid])
        {
          if ((mid - 1) % 2 == 0)
            i = mid + 1;
          else
            j = mid - 1;
        }

        else
        {
          if ((mid) % 2 == 0)
            i = mid + 1;
          else
            j = mid - 1;
        }
      }
      else
        break;
    }
    cout << i << endl;
    return nums[i];
  }
};
