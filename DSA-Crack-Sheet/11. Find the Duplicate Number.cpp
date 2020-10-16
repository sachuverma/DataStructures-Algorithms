class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    int index = 0;
    while (nums[index] > 0)
    {
      nums[index] *= -1;
      index = ((-1) * nums[index]);
    }
    return index;
  }
};
