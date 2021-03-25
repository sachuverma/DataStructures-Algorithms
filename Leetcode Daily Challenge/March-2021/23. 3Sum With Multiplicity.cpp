/*
3Sum With Multiplicity
======================

Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

As the answer can be very large, return it modulo 109 + 7.

Example 1:
Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.

Example 2:
Input: arr = [1,1,2,2,2,2], target = 5
Output: 12
Explanation: 
arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.

Constraints:
3 <= arr.length <= 3000
0 <= arr[i] <= 100
0 <= target <= 300
*/

class Solution
{
public:
  int threeSumMulti(vector<int> &A, int target)
  {
    unordered_map<int, long long> freq;
    for (auto &i : A)
      freq[i]++;
    long long ans = 0;

    for (auto &it : freq)
    {
      for (auto &jt : freq)
      {
        auto i = it.first, j = jt.first, k = target - i - j;
        if (freq.find(k) == freq.end())
          continue;
        if (i == j && j == k)
        {
          ans += freq[i] * (freq[i] - 1) * (freq[i] - 2) / 6;
        }
        else if (i == j && j != k)
        {
          ans += freq[i] * (freq[i] - 1) * freq[k] / 2;
        }
        else if (i < j && j < k)
        {
          ans += freq[i] * freq[j] * freq[k];
        }
      }
    }

    return ans % int(1e9 + 7);
  }
};
