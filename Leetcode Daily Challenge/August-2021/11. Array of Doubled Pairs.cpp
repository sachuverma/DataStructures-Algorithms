/*
Array of Doubled Pairs
======================

Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.

Example 1:
Input: arr = [3,1,3,6]
Output: false

Example 2:
Input: arr = [2,1,2,6]
Output: false

Example 3:
Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].

Example 4:
Input: arr = [1,2,4,16,8,4]
Output: false
 
Constraints:
2 <= arr.length <= 3 * 104
arr.length is even.
-105 <= arr[i] <= 105
*/

class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {

        map<int, int> nums;
        for (auto &i : arr)
            nums[i]++;

        while (nums.size() > 0)
        {
            int least = (*nums.begin()).first;
            int target;

            if (least == 0)
            {
                if (nums[least] % 2 != 0)
                    return false;
                nums.erase(least);
            }

            else
            {

                if (least < 0)
                {
                    if (least % 2 != 0)
                        return false;
                    target = least / 2;
                }
                else
                    target = 2 * least;

                int mi = min(nums[target], nums[least]);
                if (mi == 0)
                    return false;

                nums[target] -= mi;
                nums[least] -= mi;

                if (!nums[target])
                    nums.erase(target);
                if (!nums[least])
                    nums.erase(least);
            }
        }
        return true;
    }
};
