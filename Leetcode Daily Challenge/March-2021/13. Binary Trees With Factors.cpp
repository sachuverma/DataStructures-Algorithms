/*
Binary Trees With Factors
=========================

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

Example 1:
Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]

Example 2:
Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].

Constraints:
1 <= arr.length <= 1000
2 <= arr[i] <= 109
*/

#define mod 1000000007
class Solution
{
public:
  long long num(int curr, unordered_set<int> &factors, unordered_map<int, int> &memo)
  {
    if (memo.find(curr) != memo.end())
      return memo[curr];
    int ans = 1;
    for (auto &fact1 : factors)
    {
      if (curr % fact1 == 0)
      {
        int fact2 = curr / fact1;
        if (factors.find(fact2) != factors.end())
        {
          long long fact1_ans = num(fact1, factors, memo);
          long long fact2_ans = num(fact2, factors, memo);
          long long multiply = ((fact1_ans % mod) * (fact2_ans % mod)) % mod;
          ans = (ans % mod + multiply % mod) % mod;
        }
      }
    }
    memo[curr] = ans;
    return ans;
  }

  int numFactoredBinaryTrees(vector<int> &arr)
  {
    long long ans = 0;
    unordered_set<int> factors(arr.begin(), arr.end());
    unordered_map<int, int> memo;
    for (auto i = 0; i < arr.size(); ++i)
    {
      ans = (ans % mod + num(arr[i], factors, memo) % mod) % mod;
    }
    return ans;
  }
};
