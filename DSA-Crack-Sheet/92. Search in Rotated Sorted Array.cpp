
class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int mid;

    //Iterative binary search
    while (left <= right)
    {
      mid = (left + right) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] >= nums[left])
      {
        if (target <= nums[mid] && target >= nums[left])
          right = mid - 1;
        else
          left = mid + 1;
      }
      else
      {
        if (target >= nums[mid] && target <= nums[right])
          left = mid + 1;
        else
          right = mid - 1;
      }
    }
    return -1;
  }
};
