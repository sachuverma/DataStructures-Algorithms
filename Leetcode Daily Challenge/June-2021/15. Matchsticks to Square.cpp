/*
Matchsticks to Square
=====================

You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

Example 1:
Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.

Example 2:
Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.

Constraints:
1 <= matchsticks.length <= 15
0 <= matchsticks[i] <= 109

Hint #1  
Treat the matchsticks as an array. Can we split the array into 4 equal halves?

Hint #2  
Every matchstick can belong to either of the 4 sides. We don't know which one. Maybe try out all options!

Hint #3  
For every matchstick, we have to try out each of the 4 options i.e. which side it can belong to. We can make use of recursion for this.

Hint #4  
We don't really need to keep track of which matchsticks belong to a particular side during recursion. We just need to keep track of the length of each of the 4 sides.

Hint #5  
When all matchsticks have been used we simply need to see the length of all 4 sides. If they're equal, we have a square on our hands!
*/

class Solution
{
public:
  vector<int> memo;

  int dfs(vector<int> &arr, int mask, int side, int curr, int sum)
  {
    if (side == 4)
      return 1;
    if (curr > sum / 4)
      return 0;

    if (memo[mask] != -1)
      return memo[mask];

    if (curr == sum / 4)
      return memo[mask] = dfs(arr, mask, side + 1, 0, sum);

    for (int i = 0; i < arr.size(); ++i)
    {
      if (!((mask >> i) & 1))
      {
        int new_mask = (mask | (1 << i));
        if (dfs(arr, new_mask, side, curr + arr[i], sum))
          return memo[mask] = 1;
      }
    }

    return memo[mask] = 0;
  }

  bool makesquare(vector<int> &arr)
  {
    long sum = 0;
    for (auto &i : arr)
      sum += i;

    if (sum % 4 != 0)
      return false;

    int maxMask = (1 << 15) + 1;
    memo = vector<int>(maxMask, -1);

    return dfs(arr, 0, 0, 0, sum);
  }
};
