class Solution
{
public:
  void nextPermutation(vector<int> &nums)
  {
    if (nums.size() <= 1)
      return;
    int n = nums.size();
    int di = -1;

    for (int i = n - 1; i >= 1; --i)
    {
      if (nums[i] <= nums[i - 1])
        continue;
      else
      {
        di = i - 1;
        break;
      }
    }

    for (int i = n - 1; i >= di; --i)
    {
      if (di == -1)
        break;
      if (nums[i] > nums[di])
      {
        int temp = nums[i];
        nums[i] = nums[di];
        nums[di] = temp;
        break;
      }
    }

    reverse(nums.begin() + di + 1, nums.end());
  }
};