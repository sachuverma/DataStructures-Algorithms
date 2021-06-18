/*
Range Sum Query - Mutable
=========================

Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

Example 1:
Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8

Constraints:
1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
At most 3 * 104 calls will be made to update and sumRange.
*/

class NumArray
{
public:
  vector<int> arr;
  map<int, int> RGS;
  int s;

  NumArray(vector<int> &nums)
  {
    arr = nums;
    int i = 0, j = 0, n = nums.size();
    s = sqrt(n);

    while (i < n)
    {
      int sum = 0, k = 0;
      while (k < s && i < n)
      {
        sum += nums[i];
        i++;
        k++;
      }
      RGS[j] = sum;
      j++;
    }
  }

  void update(int index, int val)
  {
    int group = index / s;
    RGS[group] += (-arr[index] + val);
    arr[index] = val;
  }

  int sumRange(int left, int right)
  {
    int l = left / s, r = right / s;
    int ans = 0;
    for (int i = l; i < r; ++i)
      ans += RGS[i];
    for (int i = l * s; i < left; ++i)
      ans -= arr[i];
    for (int i = r * s; i <= right; ++i)
      ans += arr[i];
    return ans;
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */